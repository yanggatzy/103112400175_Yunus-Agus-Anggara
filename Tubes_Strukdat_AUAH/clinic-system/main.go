// main.go
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	system := NewClinicSystem()
	scanner := bufio.NewScanner(os.Stdin)

	fmt.Println("==============================================")
	fmt.Println("   SISTEM ANTRIAN PELAYANAN KLINIK")
	fmt.Println("==============================================")
	fmt.Println("Program dimulai dengan database kosong.")
	fmt.Println("Silakan input data melalui menu yang tersedia.")
	fmt.Println("==============================================")

	// Main loop - tetap berjalan sampai user benar-benar keluar
	for {
		// Login menu
		if !showLoginMenu(system, scanner) {
			fmt.Println("\n==============================================")
			fmt.Println("Terima kasih telah menggunakan sistem!")
			fmt.Println("==============================================")
			break
		}

		// Main menu based on role
		for {
			showMainMenu(system)
			fmt.Print("\nPilih menu: ")
			scanner.Scan()
			choice := strings.TrimSpace(scanner.Text())

			if choice == "0" {
				fmt.Printf("\n✓ Logout berhasil. Sampai jumpa %s!\n", system.CurrentUser)
				system.Logout()
				break // Kembali ke login menu
			}

			handleMenuChoice(system, choice, scanner)
		}
	}
}
