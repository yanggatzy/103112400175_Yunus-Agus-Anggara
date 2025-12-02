// medical_history.go
package main

import "fmt"

// ==================== SINGLE LINKED LIST (Medical History) ====================

// MedicalHistory manages patient medical records using a single linked list
type MedicalHistory struct {
	Head *MedicalRecord
}

// NewMedicalHistory creates a new empty medical history
func NewMedicalHistory() *MedicalHistory {
	return &MedicalHistory{}
}

// AddRecord adds a new medical record to the end of the list
func (mh *MedicalHistory) AddRecord(record MedicalRecord) {
	newNode := &MedicalRecord{
		Date:         record.Date,
		DoctorName:   record.DoctorName,
		Diagnosis:    record.Diagnosis,
		Prescription: record.Prescription,
		Notes:        record.Notes,
	}

	if mh.Head == nil {
		mh.Head = newNode
	} else {
		current := mh.Head
		for current.Next != nil {
			current = current.Next
		}
		current.Next = newNode
	}
}

// Display shows all medical records in chronological order
func (mh *MedicalHistory) Display() {
	if mh.Head == nil {
		fmt.Println("\nTidak ada riwayat medis")
		return
	}

	fmt.Println("\n=== RIWAYAT KUNJUNGAN PASIEN ===")
	current := mh.Head
	count := 1
	for current != nil {
		fmt.Printf("\n[%d] Tanggal: %s\n", count, current.Date.Format("02/01/2006"))
		fmt.Printf("    Dokter: %s\n", current.DoctorName)
		fmt.Printf("    Diagnosis: %s\n", current.Diagnosis)
		fmt.Printf("    Resep: %s\n", current.Prescription)
		if current.Notes != "" {
			fmt.Printf("    Catatan: %s\n", current.Notes)
		}
		current = current.Next
		count++
	}
}

// GetRecordCount returns the total number of records
func (mh *MedicalHistory) GetRecordCount() int {
	count := 0
	current := mh.Head
	for current != nil {
		count++
		current = current.Next
	}
	return count
}
