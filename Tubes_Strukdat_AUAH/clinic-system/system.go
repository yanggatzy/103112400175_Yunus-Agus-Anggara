// system.go
package main

import "fmt"

// ==================== CLINIC SYSTEM ====================

// ClinicSystem is the main system that manages all clinic operations
type ClinicSystem struct {
	Queue             *Queue
	Patients          map[string]Patient
	MedicalHistories  map[string]*MedicalHistory
	DetailedHistories map[string]*DetailedHistory
	UndoStack         *Stack
	RedoStack         *Stack
	CurrentUser       string
	CurrentRole       string
}

// NewClinicSystem creates a new instance of the clinic system
func NewClinicSystem() *ClinicSystem {
	return &ClinicSystem{
		Queue:             NewQueue(),
		Patients:          make(map[string]Patient),
		MedicalHistories:  make(map[string]*MedicalHistory),
		DetailedHistories: make(map[string]*DetailedHistory),
		UndoStack:         NewStack(),
		RedoStack:         NewStack(),
	}
}

// Login logs in a user with specified username and role
func (cs *ClinicSystem) Login(username, role string) {
	cs.CurrentUser = username
	cs.CurrentRole = role
	fmt.Printf("\n✓ Login berhasil sebagai %s (%s)\n", username, role)
}

// Logout logs out the current user without clearing system data
func (cs *ClinicSystem) Logout() {
	fmt.Printf("\nUser %s telah logout dari sistem\n", cs.CurrentUser)
	cs.CurrentUser = ""
	cs.CurrentRole = ""
	// Data TIDAK dihapus, hanya user session yang direset
}

// IsLoggedIn checks if a user is currently logged in
func (cs *ClinicSystem) IsLoggedIn() bool {
	return cs.CurrentUser != "" && cs.CurrentRole != ""
}
