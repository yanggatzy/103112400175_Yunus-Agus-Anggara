// detailed_history.go
package main

import "fmt"

// ==================== DOUBLE LINKED LIST (Detailed Medical Records) ====================

// DetailedHistory manages detailed medical records with bidirectional navigation
type DetailedHistory struct {
	Head    *DetailedRecord
	Tail    *DetailedRecord
	Current *DetailedRecord
}

// NewDetailedHistory creates a new empty detailed history
func NewDetailedHistory() *DetailedHistory {
	return &DetailedHistory{}
}

// AddRecord adds a new detailed record to the end of the list
func (dh *DetailedHistory) AddRecord(record DetailedRecord) {
	newNode := &DetailedRecord{
		Date:         record.Date,
		DoctorName:   record.DoctorName,
		Diagnosis:    record.Diagnosis,
		Prescription: record.Prescription,
		Notes:        record.Notes,
	}

	if dh.Head == nil {
		dh.Head = newNode
		dh.Tail = newNode
		dh.Current = newNode
	} else {
		dh.Tail.Next = newNode
		newNode.Prev = dh.Tail
		dh.Tail = newNode
	}
}

// NavigateNext moves to the next record
func (dh *DetailedHistory) NavigateNext() bool {
	if dh.Current != nil && dh.Current.Next != nil {
		dh.Current = dh.Current.Next
		return true
	}
	return false
}

// NavigatePrev moves to the previous record
func (dh *DetailedHistory) NavigatePrev() bool {
	if dh.Current != nil && dh.Current.Prev != nil {
		dh.Current = dh.Current.Prev
		return true
	}
	return false
}

// DisplayCurrent displays the current record with navigation hints
func (dh *DetailedHistory) DisplayCurrent() {
	if dh.Current == nil {
		fmt.Println("\nTidak ada rekam medis")
		return
	}

	fmt.Println("\n=== REKAM MEDIS DETAIL ===")
	fmt.Printf("Tanggal: %s\n", dh.Current.Date.Format("02/01/2006 15:04"))
	fmt.Printf("Dokter: %s\n", dh.Current.DoctorName)
	fmt.Printf("Diagnosis: %s\n", dh.Current.Diagnosis)
	fmt.Printf("Resep: %s\n", dh.Current.Prescription)
	fmt.Printf("Catatan: %s\n", dh.Current.Notes)

	fmt.Println("\n--- Navigasi ---")
	if dh.Current.Prev != nil {
		fmt.Println("[←] Ada rekam medis sebelumnya")
	} else {
		fmt.Println("[←] Ini adalah rekam medis pertama")
	}

	if dh.Current.Next != nil {
		fmt.Println("[→] Ada rekam medis berikutnya")
	} else {
		fmt.Println("[→] Ini adalah rekam medis terakhir")
	}
}

// ResetToHead resets current pointer to the first record
func (dh *DetailedHistory) ResetToHead() {
	dh.Current = dh.Head
}

// ResetToTail resets current pointer to the last record
func (dh *DetailedHistory) ResetToTail() {
	dh.Current = dh.Tail
}
