// pharmacist_handler.go
package main

import (
	"fmt"
	"time"
)

// handlePharmacistMenu handles all pharmacist menu operations
func handlePharmacistMenu(system *ClinicSystem, choice string) {
	switch choice {
	case "1":
		showPendingPrescriptions(system)
	case "2":
		processPrescription(system)
	case "3":
		callPatientForMedicine(system)
	default:
		fmt.Println("\n⚠ Menu tidak valid")
	}
}

// showPendingPrescriptions displays all prescriptions waiting to be processed
func showPendingPrescriptions(system *ClinicSystem) {
	fmt.Println("\n╔════════════════════════════════════════════╗")
	fmt.Println("║          RESEP MENUNGGU PROSES             ║")
	fmt.Println("╚════════════════════════════════════════════╝")

	hasData := false
	count := 1

	// Find patients with completed status who have prescriptions
	current := system.Queue.Front
	for current != nil {
		if current.Status == "completed" {
			// Check if patient has medical history with prescription
			if history, exists := system.MedicalHistories[current.Patient.ID]; exists {
				// Get the last record
				lastRecord := history.Head
				for lastRecord != nil && lastRecord.Next != nil {
					lastRecord = lastRecord.Next
				}

				if lastRecord != nil && lastRecord.Prescription != "" {
					fmt.Printf("\n[%d] RESEP #%d\n", count, current.QueueNum)
					fmt.Printf("─────────────────────────────────────────\n")
					fmt.Printf("👤 Pasien: %s (ID: %s)\n", current.Patient.Name, current.Patient.ID)
					fmt.Printf("💊 Resep: %s\n", lastRecord.Prescription)
					fmt.Printf("👨‍⚕️ Dokter: %s\n", lastRecord.DoctorName)
					fmt.Printf("📅 Tanggal: %s\n", lastRecord.Date.Format("02/01/2006 15:04"))
					fmt.Printf("💳 Asuransi: %s\n", current.Patient.Insurance)
					fmt.Printf("📞 Telepon: %s\n", current.Patient.Phone)

					if lastRecord.Notes != "" {
						fmt.Printf("📝 Catatan: %s\n", lastRecord.Notes)
					}

					fmt.Printf("🔔 Status: Menunggu Proses\n")
					hasData = true
					count++
				}
			}
		}
		current = current.Next
	}

	if !hasData {
		fmt.Println("\n✅ Tidak ada resep yang menunggu")
		fmt.Println("Semua resep sudah diproses atau belum ada pasien selesai pemeriksaan.")
	} else {
		fmt.Printf("\n📊 Total resep menunggu: %d\n", count-1)
	}
}

// processPrescription simulates prescription processing
func processPrescription(system *ClinicSystem) {
	fmt.Println("\n╔════════════════════════════════════════════╗")
	fmt.Println("║           PROSES RESEP OBAT                ║")
	fmt.Println("╚════════════════════════════════════════════╝")

	// Find first prescription to process
	current := system.Queue.Front
	var foundPatient *QueueNode
	var prescription string

	for current != nil {
		if current.Status == "completed" {
			if history, exists := system.MedicalHistories[current.Patient.ID]; exists {
				lastRecord := history.Head
				for lastRecord != nil && lastRecord.Next != nil {
					lastRecord = lastRecord.Next
				}
				if lastRecord != nil && lastRecord.Prescription != "" {
					foundPatient = current
					prescription = lastRecord.Prescription
					break
				}
			}
		}
		current = current.Next
	}

	if foundPatient == nil {
		fmt.Println("\n⚠ Tidak ada resep untuk diproses")
		return
	}

	fmt.Printf("\n🔄 Memproses resep untuk: %s\n", foundPatient.Patient.Name)
	fmt.Printf("💊 Resep: %s\n", prescription)
	fmt.Println("\n⏳ Sedang memproses...")

	// Simulate processing time
	time.Sleep(2 * time.Second)

	fmt.Println("\n✅ RESEP BERHASIL DIPROSES")
	fmt.Printf("📋 Nomor Antrian: %d\n", foundPatient.QueueNum)
	fmt.Printf("👤 Pasien: %s\n", foundPatient.Patient.Name)
	fmt.Printf("⏰ Waktu Proses: %s\n", time.Now().Format("15:04:05"))
	fmt.Println("\n💊 Obat siap untuk diambil pasien")
	fmt.Println("📢 Silakan panggil pasien untuk pengambilan obat (Menu 3)")
}

// callPatientForMedicine calls patient to pick up their medicine
func callPatientForMedicine(system *ClinicSystem) {
	fmt.Println("\n╔════════════════════════════════════════════╗")
	fmt.Println("║      PANGGILAN PENGAMBILAN OBAT            ║")
	fmt.Println("╚════════════════════════════════════════════╝")

	// Find completed patients
	current := system.Queue.Front
	found := false
	callCount := 0

	fmt.Println("\n📢 PENGUMUMAN:")
	fmt.Println("─────────────────────────────────────────")

	for current != nil {
		if current.Status == "completed" && callCount < 3 {
			// Check if patient has prescription
			if history, exists := system.MedicalHistories[current.Patient.ID]; exists {
				lastRecord := history.Head
				for lastRecord != nil && lastRecord.Next != nil {
					lastRecord = lastRecord.Next
				}
				if lastRecord != nil && lastRecord.Prescription != "" {
					fmt.Printf("\n🔔 NOMOR ANTRIAN: %d\n", current.QueueNum)
					fmt.Printf("👤 Nama: %s\n", current.Patient.Name)
					fmt.Printf("📍 Silakan ke loket farmasi untuk\n")
					fmt.Printf("   mengambil obat Anda\n")
					fmt.Printf("⏰ Waktu: %s\n", time.Now().Format("15:04:05"))
					found = true
					callCount++
				}
			}
		}
		current = current.Next
	}

	if !found {
		fmt.Println("\n⚠ Tidak ada pasien yang siap mengambil obat")
		fmt.Println("Pastikan resep sudah diproses terlebih dahulu.")
	} else {
		fmt.Println("\n─────────────────────────────────────────")
		fmt.Printf("✅ Total panggilan: %d pasien\n", callCount)
		fmt.Println("\n💡 CATATAN:")
		fmt.Println("• Pastikan membawa nomor antrian")
		fmt.Println("• Tunjukkan kartu identitas/asuransi")
		fmt.Println("• Dengarkan penjelasan cara minum obat")
	}
}

// Additional helper function to get prescription statistics
func getPrescriptionStats(system *ClinicSystem) (total, processed, pending int) {
	current := system.Queue.Front
	for current != nil {
		if history, exists := system.MedicalHistories[current.Patient.ID]; exists {
			lastRecord := history.Head
			for lastRecord != nil && lastRecord.Next != nil {
				lastRecord = lastRecord.Next
			}
			if lastRecord != nil && lastRecord.Prescription != "" {
				total++
				if current.Status == "completed" {
					pending++
				}
			}
		}
		current = current.Next
	}
	processed = total - pending
	return
}
