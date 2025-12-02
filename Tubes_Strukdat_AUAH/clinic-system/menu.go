// menu.go
package main

import (
	"bufio"
	"fmt"
	"strings"
)

// showLoginMenu displays the login menu and returns false if user wants to exit
func showLoginMenu(system *ClinicSystem, scanner *bufio.Scanner) bool {
	fmt.Println("\n=== LOGIN ===")
	fmt.Println("1. Admin Klinik")
	fmt.Println("2. Petugas Pendaftaran")
	fmt.Println("3. Dokter")
	fmt.Println("4. Apoteker")
	fmt.Println("5. Exit Program")
	fmt.Print("\nPilih role: ")

	scanner.Scan()
	choice := strings.TrimSpace(scanner.Text())

	switch choice {
	case "1":
		system.Login("Admin", "ADMIN")
		return true
	case "2":
		system.Login("Receptionist", "RECEPTIONIST")
		return true
	case "3":
		system.Login("Dr. Susanto", "DOCTOR")
		return true
	case "4":
		system.Login("Pharmacist", "PHARMACIST")
		return true
	case "5":
		return false // Exit program
	default:
		fmt.Println("\n⚠ Pilihan tidak valid, silakan coba lagi")
		return showLoginMenu(system, scanner)
	}
}

// showMainMenu displays the main menu based on current user role
func showMainMenu(system *ClinicSystem) {
	fmt.Println("\n==============================================")
	fmt.Printf("User: %s | Role: %s\n", system.CurrentUser, system.CurrentRole)
	fmt.Println("==============================================")

	switch system.CurrentRole {
	case "ADMIN":
		fmt.Println("1. Lihat Dashboard Antrian")
		fmt.Println("2. Laporan Harian")
		fmt.Println("3. Monitoring Kinerja")

	case "RECEPTIONIST":
		fmt.Println("1. Daftar Pasien Baru ke Antrian")
		fmt.Println("2. Lihat Antrian")
		fmt.Println("3. Update Data Pasien")
		fmt.Println("4. Cetak Nomor Antrian")

	case "DOCTOR":
		fmt.Println("1. Panggil Pasien Berikutnya")
		fmt.Println("2. Lihat Riwayat Kunjungan (Single LL)")
		fmt.Println("3. Navigasi Rekam Medis Detail (Double LL)")
		fmt.Println("4. Input Diagnosa & Resep")
		fmt.Println("5. Undo/Redo Operasi (Stack)")

	case "PHARMACIST":
		fmt.Println("1. Lihat Resep Menunggu")
		fmt.Println("2. Proses Resep")
		fmt.Println("3. Panggil Pasien Ambil Obat")

	default:
		fmt.Println("Role tidak dikenali")
	}

	fmt.Println("0. Logout")
}

// handleMenuChoice routes the menu selection to appropriate handler
func handleMenuChoice(system *ClinicSystem, choice string, scanner *bufio.Scanner) {
	switch system.CurrentRole {
	case "RECEPTIONIST":
		handleReceptionistMenu(system, choice, scanner)
	case "DOCTOR":
		handleDoctorMenu(system, choice, scanner)
	case "ADMIN":
		handleAdminMenu(system, choice)
	case "PHARMACIST":
		handlePharmacistMenu(system, choice)
	default:
		fmt.Println("\n⚠ Role tidak dikenali")
	}
}
