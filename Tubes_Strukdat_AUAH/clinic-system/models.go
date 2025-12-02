// models.go
package main

import "time"

// ==================== MODELS ====================

// Patient represents a patient in the clinic system
type Patient struct {
	ID               string
	Name             string
	Phone            string
	Insurance        string
	RegistrationTime time.Time
}

// MedicalRecord represents a single medical record in a linked list
type MedicalRecord struct {
	Date         time.Time
	DoctorName   string
	Diagnosis    string
	Prescription string
	Notes        string
	Next         *MedicalRecord // Single Linked List pointer
}

// DetailedRecord represents a detailed medical record with bidirectional navigation
type DetailedRecord struct {
	Date         time.Time
	DoctorName   string
	Diagnosis    string
	Prescription string
	Notes        string
	Prev         *DetailedRecord // Double Linked List - previous pointer
	Next         *DetailedRecord // Double Linked List - next pointer
}

// QueueNode represents a node in the queue
type QueueNode struct {
	Patient  Patient
	QueueNum int
	Status   string // "waiting", "in_progress", "completed"
	DoctorID string
	Next     *QueueNode
}

// OperationLog represents a log entry for undo/redo operations
type OperationLog struct {
	Action    string
	Data      interface{}
	Timestamp time.Time
	Next      *OperationLog
}
