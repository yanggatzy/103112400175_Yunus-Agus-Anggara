// receptionist_handler.go
package main

import (
	"bufio"
	"fmt"
	"strings"
	"time"
)

// handleReceptionistMenu handles all receptionist menu operations
func handleReceptionistMenu(system *ClinicSystem, choice string, scanner *bufio.Scanner) {
	switch choice {
	case "1":
		registerNewPatient(system, scanner)
	case "2":
		system.Queue.DisplayAll()
	case "3":
		updatePatientData(system, scanner)
	case "4":
		printQueueNumber(system)
	default:
		fmt.Println("\n⚠ Menu tidak valid")
	}
}

// registerNewPatient registers a new patient and adds them to the queue
func registerNewPatient(system *ClinicSystem, scanner *bufio.Scanner) {
	fmt.Println("\n=== PENDAFTARAN PASIEN BARU ===")

	fmt.Print("ID Pasien: ")
	scanner.Scan()
	id := strings.TrimSpace(scanner.Text())

	// Check if ID already exists
	if _, exists := system.Patients[id]; exists {
		fmt.Println("\n⚠ ID Pasien sudah terdaftar!")
		return
	}

	fmt.Print("Nama: ")
	scanner.Scan()
	name := strings.TrimSpace(scanner.Text())

	if name == "" {
		fmt.Println("\n⚠ Nama tidak boleh kosong!")
		return
	}

	fmt.Print("Telepon: ")
	scanner.Scan()
	phone := strings.TrimSpace(scanner.Text())

	fmt.Print("Asuransi (BPJS/Mandiri/Umum/dll): ")
	scanner.Scan()
	insurance := strings.TrimSpace(scanner.Text())

	if insurance == "" {
		insurance = "Umum"
	}

	patient := Patient{
		ID:               id,
		Name:             name,
		Phone:            phone,
		Insurance:        insurance,
		RegistrationTime: time.Now(),
	}

	system.Patients[id] = patient
	queueNum := system.Queue.Enqueue(patient, "DR001")

	fmt.Println("\n✓ Pasien berhasil didaftarkan!")
	fmt.Printf("Nomor Antrian: %d\n", queueNum)
	fmt.Printf("Waktu Pendaftaran: %s\n", patient.RegistrationTime.Format("15:04:05"))
	fmt.Printf("Dokter yang dituju: DR001\n")
}

// updatePatientData updates existing patient information
func updatePatientData(system *ClinicSystem, scanner *bufio.Scanner) {
	fmt.Println("\n=== UPDATE DATA PASIEN ===")

	fmt.Print("Masukkan ID Pasien yang akan diupdate: ")
	scanner.Scan()
	id := strings.TrimSpace(scanner.Text())

	patient, exists := system.Patients[id]
	if !exists {
		fmt.Println("\n⚠ Pasien tidak ditemukan!")
		return
	}

	fmt.Printf("\nData Pasien Saat Ini:\n")
	fmt.Printf("ID: %s\n", patient.ID)
	fmt.Printf("Nama: %s\n", patient.Name)
	fmt.Printf("Telepon: %s\n", patient.Phone)
	fmt.Printf("Asuransi: %s\n", patient.Insurance)

	fmt.Print("\nTelepon baru (tekan Enter untuk tidak mengubah): ")
	scanner.Scan()
	newPhone := strings.TrimSpace(scanner.Text())
	if newPhone != "" {
		patient.Phone = newPhone
	}

	fmt.Print("Asuransi baru (tekan Enter untuk tidak mengubah): ")
	scanner.Scan()
	newInsurance := strings.TrimSpace(scanner.Text())
	if newInsurance != "" {
		patient.Insurance = newInsurance
	}

	system.Patients[id] = patient
	fmt.Println("\n✓ Data pasien berhasil diupdate")
}

// printQueueNumber prints the queue number ticket for the next patient
func printQueueNumber(system *ClinicSystem) {
	if system.Queue.IsEmpty() {
		fmt.Println("\n⚠ Tidak ada antrian")
		return
	}

	node := system.Queue.Peek()
	fmt.Println("\n========================================")
	fmt.Println("        NOMOR ANTRIAN KLINIK")
	fmt.Println("========================================")
	fmt.Printf("\n         No. %d\n\n", node.QueueNum)
	fmt.Printf("   Nama: %s\n", node.Patient.Name)
	fmt.Printf("   Dokter: %s\n", node.DoctorID)
	fmt.Printf("   Waktu: %s\n", time.Now().Format("15:04:05"))
	fmt.Printf("\n========================================")
	fmt.Println("\n   Harap menunggu panggilan dokter")
	fmt.Println("========================================\n")
}
