// doctor_handler.go
package main

import (
	"bufio"
	"fmt"
	"strings"
	"time"
)

// handleDoctorMenu handles all doctor menu operations
func handleDoctorMenu(system *ClinicSystem, choice string, scanner *bufio.Scanner) {
	switch choice {
	case "1":
		callNextPatient(system)
	case "2":
		viewMedicalHistory(system, scanner)
	case "3":
		navigateDetailedRecords(system, scanner)
	case "4":
		inputDiagnosisAndPrescription(system, scanner)
	case "5":
		handleUndoRedo(system, scanner)
	default:
		fmt.Println("\n⚠ Menu tidak valid")
	}
}

// callNextPatient calls the next waiting patient
func callNextPatient(system *ClinicSystem) {
	node := system.Queue.GetByDoctorID("DR001")
	if node == nil {
		fmt.Println("\n⚠ Tidak ada pasien dalam antrian")
		return
	}

	fmt.Println("\n=== PANGGIL PASIEN ===")
	fmt.Printf("✓ Memanggil pasien: %s (No. %d)\n", node.Patient.Name, node.QueueNum)
	fmt.Printf("ID Pasien: %s\n", node.Patient.ID)
	fmt.Printf("Telepon: %s\n", node.Patient.Phone)
	fmt.Printf("Asuransi: %s\n", node.Patient.Insurance)
	fmt.Printf("Waktu Pendaftaran: %s\n", node.Patient.RegistrationTime.Format("15:04:05"))

	node.Status = "in_progress"
	fmt.Println("\n✓ Status pasien diubah menjadi: Sedang Dilayani")
}

// viewMedicalHistory displays patient's medical history using single linked list
func viewMedicalHistory(system *ClinicSystem, scanner *bufio.Scanner) {
	fmt.Println("\n=== LIHAT RIWAYAT KUNJUNGAN ===")
	fmt.Print("Masukkan ID Pasien: ")
	scanner.Scan()
	id := strings.TrimSpace(scanner.Text())

	// Check if patient exists
	if _, exists := system.Patients[id]; !exists {
		fmt.Println("\n⚠ Pasien tidak ditemukan dalam database")
		return
	}

	if history, exists := system.MedicalHistories[id]; exists {
		history.Display()
		fmt.Printf("\n📊 Total kunjungan: %d\n", history.GetRecordCount())
	} else {
		fmt.Println("\n⚠ Pasien belum memiliki riwayat medis")
		fmt.Println("Ini adalah kunjungan pertama pasien.")
	}
}

// navigateDetailedRecords allows navigation through detailed medical records using double linked list
func navigateDetailedRecords(system *ClinicSystem, scanner *bufio.Scanner) {
	fmt.Println("\n=== NAVIGASI REKAM MEDIS DETAIL ===")
	fmt.Print("Masukkan ID Pasien: ")
	scanner.Scan()
	id := strings.TrimSpace(scanner.Text())

	// Check if patient exists
	if _, exists := system.Patients[id]; !exists {
		fmt.Println("\n⚠ Pasien tidak ditemukan dalam database")
		return
	}

	history, exists := system.DetailedHistories[id]
	if !exists {
		fmt.Println("\n⚠ Pasien belum memiliki rekam medis detail")
		return
	}

	// Reset to first record
	history.ResetToHead()
	history.DisplayCurrent()

	fmt.Println("\n=== NAVIGASI ===")
	fmt.Println("[n] Next (Rekam Medis Berikutnya)")
	fmt.Println("[p] Previous (Rekam Medis Sebelumnya)")
	fmt.Println("[q] Quit (Keluar)")

	for {
		fmt.Print("\nPilih: ")
		scanner.Scan()
		nav := strings.TrimSpace(strings.ToLower(scanner.Text()))

		switch nav {
		case "q":
			fmt.Println("\n✓ Keluar dari navigasi rekam medis")
			return
		case "n":
			if history.NavigateNext() {
				history.DisplayCurrent()
			} else {
				fmt.Println("\n⚠ Sudah di akhir rekam medis")
			}
		case "p":
			if history.NavigatePrev() {
				history.DisplayCurrent()
			} else {
				fmt.Println("\n⚠ Sudah di awal rekam medis")
			}
		default:
			fmt.Println("\n⚠ Perintah tidak valid. Gunakan [n/p/q]")
		}
	}
}

// inputDiagnosisAndPrescription allows doctor to input diagnosis and prescription
func inputDiagnosisAndPrescription(system *ClinicSystem, scanner *bufio.Scanner) {
	fmt.Println("\n=== INPUT DIAGNOSA & RESEP ===")

	fmt.Print("Masukkan ID Pasien: ")
	scanner.Scan()
	id := strings.TrimSpace(scanner.Text())

	// Check if patient exists
	if _, exists := system.Patients[id]; !exists {
		fmt.Println("\n⚠ Pasien tidak ditemukan!")
		return
	}

	fmt.Print("Diagnosis: ")
	scanner.Scan()
	diagnosis := strings.TrimSpace(scanner.Text())

	if diagnosis == "" {
		fmt.Println("\n⚠ Diagnosis tidak boleh kosong!")
		return
	}

	fmt.Print("Resep: ")
	scanner.Scan()
	prescription := strings.TrimSpace(scanner.Text())

	fmt.Print("Catatan tambahan (opsional): ")
	scanner.Scan()
	notes := strings.TrimSpace(scanner.Text())

	currentTime := time.Now()

	// Create medical record for single linked list
	record := MedicalRecord{
		Date:         currentTime,
		DoctorName:   system.CurrentUser,
		Diagnosis:    diagnosis,
		Prescription: prescription,
		Notes:        notes,
	}

	// Create detailed record for double linked list
	detailedRecord := DetailedRecord{
		Date:         currentTime,
		DoctorName:   system.CurrentUser,
		Diagnosis:    diagnosis,
		Prescription: prescription,
		Notes:        notes,
	}

	// Save to MedicalHistory (Single Linked List)
	if _, exists := system.MedicalHistories[id]; !exists {
		system.MedicalHistories[id] = NewMedicalHistory()
	}
	system.MedicalHistories[id].AddRecord(record)

	// Save to DetailedHistory (Double Linked List)
	if _, exists := system.DetailedHistories[id]; !exists {
		system.DetailedHistories[id] = NewDetailedHistory()
	}
	system.DetailedHistories[id].AddRecord(detailedRecord)

	// Save to undo stack
	system.UndoStack.Push("ADD_RECORD", record)

	// Update patient status in queue
	current := system.Queue.Front
	for current != nil {
		if current.Patient.ID == id && current.Status == "in_progress" {
			current.Status = "completed"
			break
		}
		current = current.Next
	}

	fmt.Println("\n✓ Rekam medis berhasil disimpan")
	fmt.Printf("Waktu: %s\n", currentTime.Format("02/01/2006 15:04:05"))
	fmt.Println("✓ Status pasien diubah menjadi: Selesai")
}

// handleUndoRedo handles undo and redo operations for medical records
func handleUndoRedo(system *ClinicSystem, scanner *bufio.Scanner) {
	fmt.Println("\n=== UNDO/REDO OPERASI ===")
	system.UndoStack.Display()

	fmt.Println("\n=== PILIHAN ===")
	fmt.Println("[u] Undo - Batalkan operasi terakhir")
	fmt.Println("[r] Redo - Ulangi operasi yang dibatalkan")
	fmt.Println("[q] Quit - Keluar")

	fmt.Print("\nPilih: ")
	scanner.Scan()
	action := strings.TrimSpace(strings.ToLower(scanner.Text()))

	switch action {
	case "u":
		if log := system.UndoStack.Pop(); log != nil {
			system.RedoStack.Push(log.Action, log.Data)
			fmt.Printf("\n✓ Undo: %s\n", log.Action)
			fmt.Printf("Waktu operasi: %s\n", log.Timestamp.Format("15:04:05"))
			fmt.Println("\n⚠ Catatan: Operasi undo dalam implementasi ini bersifat symbolic.")
			fmt.Println("Untuk implementasi penuh, diperlukan logic penghapusan data.")
		} else {
			fmt.Println("\n⚠ Tidak ada operasi untuk di-undo")
		}
	case "r":
		if log := system.RedoStack.Pop(); log != nil {
			system.UndoStack.Push(log.Action, log.Data)
			fmt.Printf("\n✓ Redo: %s\n", log.Action)
			fmt.Printf("Waktu operasi: %s\n", log.Timestamp.Format("15:04:05"))
		} else {
			fmt.Println("\n⚠ Tidak ada operasi untuk di-redo")
		}
	case "q":
		fmt.Println("\n✓ Keluar dari menu undo/redo")
	default:
		fmt.Println("\n⚠ Pilihan tidak valid")
	}
}
