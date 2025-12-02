// admin_handler.go
package main

import (
	"fmt"
	"time"
)

// handleAdminMenu handles all admin menu operations
func handleAdminMenu(system *ClinicSystem, choice string) {
	switch choice {
	case "1":
		showDashboard(system)
	case "2":
		showDailyReport(system)
	case "3":
		showPerformanceMonitoring(system)
	default:
		fmt.Println("\n⚠ Menu tidak valid")
	}
}

// showDashboard displays real-time dashboard of clinic operations
func showDashboard(system *ClinicSystem) {
	fmt.Println("\n╔════════════════════════════════════════════╗")
	fmt.Println("║       DASHBOARD MONITORING KLINIK          ║")
	fmt.Println("╚════════════════════════════════════════════╝")
	fmt.Printf("\n📅 Tanggal: %s\n", time.Now().Format("02/01/2006 15:04:05"))

	fmt.Println("\n--- STATISTIK UMUM ---")
	fmt.Printf("👥 Total Pasien Terdaftar: %d\n", len(system.Patients))
	fmt.Printf("📋 Total Nomor Antrian Hari Ini: %d\n", system.Queue.NextNum-1)
	fmt.Printf("⏳ Antrian Aktif: %d\n", system.Queue.Count)

	// Count queue status
	waiting, inProgress, completed := countQueueStatus(system)

	fmt.Println("\n--- STATUS ANTRIAN ---")
	fmt.Printf("⏱️  Menunggu: %d pasien\n", waiting)
	fmt.Printf("🏥 Sedang Dilayani: %d pasien\n", inProgress)
	fmt.Printf("✅ Selesai: %d pasien\n", completed)

	// Medical records statistics
	totalRecords := 0
	for _, history := range system.MedicalHistories {
		totalRecords += history.GetRecordCount()
	}
	fmt.Printf("\n📝 Total Rekam Medis: %d\n", totalRecords)

	// Display queue details
	system.Queue.DisplayAll()
}

// showDailyReport generates daily report of clinic operations
func showDailyReport(system *ClinicSystem) {
	fmt.Println("\n╔════════════════════════════════════════════╗")
	fmt.Println("║          LAPORAN HARIAN KLINIK             ║")
	fmt.Println("╚════════════════════════════════════════════╝")
	fmt.Printf("\n📅 Tanggal: %s\n", time.Now().Format("02 January 2006"))
	fmt.Printf("⏰ Waktu Laporan: %s\n", time.Now().Format("15:04:05"))

	fmt.Println("\n--- RINGKASAN KUNJUNGAN ---")
	fmt.Printf("📊 Total Kunjungan: %d pasien\n", system.Queue.NextNum-1)

	waiting, inProgress, completed := countQueueStatus(system)
	fmt.Printf("⏳ Masih Menunggu: %d pasien\n", waiting)
	fmt.Printf("🏥 Sedang Dilayani: %d pasien\n", inProgress)
	fmt.Printf("✅ Selesai Dilayani: %d pasien\n", completed)

	fmt.Println("\n--- STATISTIK REKAM MEDIS ---")
	totalRecords := 0
	for _, history := range system.MedicalHistories {
		totalRecords += history.GetRecordCount()
	}
	fmt.Printf("📝 Rekam Medis Dibuat: %d\n", totalRecords)

	// Calculate percentage
	if system.Queue.NextNum > 1 {
		completionRate := float64(completed) / float64(system.Queue.NextNum-1) * 100
		fmt.Printf("📈 Tingkat Penyelesaian: %.1f%%\n", completionRate)
	}

	fmt.Println("\n--- PASIEN TERDAFTAR ---")
	fmt.Printf("👥 Total Pasien dalam Database: %d\n", len(system.Patients))

	// Insurance breakdown
	if len(system.Patients) > 0 {
		fmt.Println("\n--- BREAKDOWN ASURANSI ---")
		insuranceCount := make(map[string]int)
		for _, patient := range system.Patients {
			insuranceCount[patient.Insurance]++
		}
		for insurance, count := range insuranceCount {
			fmt.Printf("   • %s: %d pasien\n", insurance, count)
		}
	}
}

// showPerformanceMonitoring displays performance metrics and KPIs
func showPerformanceMonitoring(system *ClinicSystem) {
	fmt.Println("\n╔════════════════════════════════════════════╗")
	fmt.Println("║        MONITORING KINERJA KLINIK           ║")
	fmt.Println("╚════════════════════════════════════════════╝")
	fmt.Printf("\n⏰ Waktu Monitoring: %s\n", time.Now().Format("02/01/2006 15:04:05"))

	fmt.Println("\n--- KEY PERFORMANCE INDICATORS ---")

	// Basic statistics
	fmt.Printf("📊 Total Pasien Terdaftar: %d\n", len(system.Patients))
	fmt.Printf("📋 Total Antrian Diproses: %d\n", system.Queue.NextNum-1)
	fmt.Printf("⏳ Antrian Aktif Saat Ini: %d\n", system.Queue.Count)

	// Queue performance
	waiting, inProgress, completed := countQueueStatus(system)

	fmt.Println("\n--- EFISIENSI ANTRIAN ---")
	if system.Queue.NextNum > 1 {
		efficiency := float64(completed) / float64(system.Queue.NextNum-1) * 100
		fmt.Printf("✅ Tingkat Penyelesaian: %.1f%%\n", efficiency)
		fmt.Printf("⏱️  Pasien Menunggu: %d (%.1f%%)\n", waiting, float64(waiting)/float64(system.Queue.NextNum-1)*100)
		fmt.Printf("🏥 Sedang Dilayani: %d (%.1f%%)\n", inProgress, float64(inProgress)/float64(system.Queue.NextNum-1)*100)
	} else {
		fmt.Println("📊 Belum ada data untuk dihitung")
	}

	// Estimated waiting time (simple calculation: 15 minutes per patient)
	avgWaitTime := waiting * 15
	fmt.Printf("\n⏰ Estimasi Waktu Tunggu: ~%d menit\n", avgWaitTime)

	// Service capacity
	fmt.Println("\n--- KAPASITAS LAYANAN ---")
	fmt.Printf("👨‍⚕️ Dokter Aktif: 1 (DR001)\n")
	fmt.Printf("💺 Kapasitas Antrian: Unlimited\n")
	fmt.Printf("📈 Utilisasi: %d pasien hari ini\n", system.Queue.NextNum-1)

	// Patient satisfaction (dummy data for demonstration)
	fmt.Println("\n--- KEPUASAN PASIEN ---")
	fmt.Println("⭐ Rating Layanan: 4.2/5.0")
	fmt.Println("😊 Tingkat Kepuasan: 85%")
	fmt.Println("💬 Feedback Positif: 92%")

	// Medical records productivity
	totalRecords := 0
	for _, history := range system.MedicalHistories {
		totalRecords += history.GetRecordCount()
	}

	fmt.Println("\n--- PRODUKTIVITAS REKAM MEDIS ---")
	fmt.Printf("📝 Total Rekam Medis: %d\n", totalRecords)
	if completed > 0 {
		recordRate := float64(totalRecords) / float64(completed) * 100
		fmt.Printf("📊 Tingkat Dokumentasi: %.1f%%\n", recordRate)
	}

	fmt.Println("\n--- REKOMENDASI ---")
	if waiting > 5 {
		fmt.Println("⚠️  Antrian panjang! Pertimbangkan menambah dokter")
	} else if waiting == 0 {
		fmt.Println("✅ Tidak ada antrian - Layanan optimal")
	} else {
		fmt.Println("✅ Antrian dalam kondisi normal")
	}
}

// countQueueStatus counts patients by their status in the queue
func countQueueStatus(system *ClinicSystem) (waiting, inProgress, completed int) {
	current := system.Queue.Front
	for current != nil {
		switch current.Status {
		case "waiting":
			waiting++
		case "in_progress":
			inProgress++
		case "completed":
			completed++
		}
		current = current.Next
	}

	// Calculate completed from total processed minus active queue
	totalProcessed := system.Queue.NextNum - 1
	activeQueue := waiting + inProgress
	completed = totalProcessed - activeQueue

	return
}
