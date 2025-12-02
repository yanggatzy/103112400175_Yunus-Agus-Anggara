package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"time"
)

// ========================= MODELS & ADT =========================

// ---------- Patient ----------
type Patient struct {
	ID               string
	Name             string
	Age              int
	Address          string
	Phone            string
	Insurance        string
	RegistrationTime time.Time
	QueueNo          int
}

// ---------- Queue (Antrian Pasien) ----------
type Queue struct {
	nodes   []Patient
	counter int // to generate queue numbers
}

func NewQueue() *Queue { return &Queue{nodes: make([]Patient, 0)} }

func (q *Queue) Enqueue(p Patient) int {
	q.counter++
	p.QueueNo = q.counter
	q.nodes = append(q.nodes, p)
	return p.QueueNo
}

func (q *Queue) Dequeue() (Patient, bool) {
	if len(q.nodes) == 0 {
		return Patient{}, false
	}
	p := q.nodes[0]
	q.nodes = q.nodes[1:]
	return p, true
}

func (q *Queue) Peek() (Patient, bool) {
	if len(q.nodes) == 0 {
		return Patient{}, false
	}
	return q.nodes[0], true
}

func (q *Queue) IsEmpty() bool {
	return len(q.nodes) == 0
}

func (q *Queue) Print() {
	if len(q.nodes) == 0 {
		fmt.Println("Antrian kosong.")
		return
	}
	fmt.Println("\n--- DAFTAR ANTRIAN ---")
	for _, p := range q.nodes {
		fmt.Printf("No.%d | %s | Age:%d | %s | Asuransi:%s\n",
			p.QueueNo, p.Name, p.Age, p.Phone, p.Insurance)
	}
}

func (q *Queue) FindByID(id string) (*Patient, bool) {
	for i := range q.nodes {
		if q.nodes[i].ID == id {
			return &q.nodes[i], true
		}
	}
	return nil, false
}

func (q *Queue) RemoveByQueueNo(no int) bool {
	for i := range q.nodes {
		if q.nodes[i].QueueNo == no {
			q.nodes = append(q.nodes[:i], q.nodes[i+1:]...)
			return true
		}
	}
	return false
}

// ---------- Single Linked List (Visit History) ----------
type MedicalRecord struct {
	Date         time.Time
	DoctorName   string
	Diagnosis    string
	Prescription string
	Notes        string
	Next         *MedicalRecord
}

type MedicalHistory struct {
	Head *MedicalRecord
}

func NewMedicalHistory() *MedicalHistory { return &MedicalHistory{} }

func (mh *MedicalHistory) AddRecord(rec MedicalRecord) {
	n := &MedicalRecord{
		Date:         rec.Date,
		DoctorName:   rec.DoctorName,
		Diagnosis:    rec.Diagnosis,
		Prescription: rec.Prescription,
		Notes:        rec.Notes,
	}
	if mh.Head == nil {
		mh.Head = n
	} else {
		cur := mh.Head
		for cur.Next != nil {
			cur = cur.Next
		}
		cur.Next = n
	}
}

func (mh *MedicalHistory) RemoveLastRecord() *MedicalRecord {
	if mh.Head == nil {
		return nil
	}
	if mh.Head.Next == nil {
		r := mh.Head
		mh.Head = nil
		return r
	}
	prev := mh.Head
	cur := mh.Head.Next
	for cur.Next != nil {
		prev = cur
		cur = cur.Next
	}
	prev.Next = nil
	return cur
}

func (mh *MedicalHistory) Count() int {
	c := 0
	cur := mh.Head
	for cur != nil {
		c++
		cur = cur.Next
	}
	return c
}

func (mh *MedicalHistory) Display() {
	if mh.Head == nil {
		fmt.Println("Tidak ada riwayat medis.")
		return
	}
	fmt.Println("\n=== RIWAYAT KUNJUNGAN ===")
	i := 1
	cur := mh.Head
	for cur != nil {
		fmt.Printf("[%d] %s | Dokter: %s | Diagnosa: %s | Resep: %s | Catatan: %s\n",
			i, cur.Date.Format("02/01/2006 15:04"), cur.DoctorName, cur.Diagnosis, cur.Prescription, cur.Notes)
		i++
		cur = cur.Next
	}
}

// ---------- Double Linked List (Detailed History) ----------
type DetailedRecord struct {
	Date         time.Time
	DoctorName   string
	Diagnosis    string
	Prescription string
	Notes        string
	Prev         *DetailedRecord
	Next         *DetailedRecord
}

type DetailedHistory struct {
	Head    *DetailedRecord
	Tail    *DetailedRecord
	Current *DetailedRecord
}

func NewDetailedHistory() *DetailedHistory { return &DetailedHistory{} }

func (dh *DetailedHistory) AddRecord(rec DetailedRecord) {
	n := &DetailedRecord{
		Date:         rec.Date,
		DoctorName:   rec.DoctorName,
		Diagnosis:    rec.Diagnosis,
		Prescription: rec.Prescription,
		Notes:        rec.Notes,
	}
	if dh.Head == nil {
		dh.Head = n
		dh.Tail = n
		dh.Current = n
	} else {
		dh.Tail.Next = n
		n.Prev = dh.Tail
		dh.Tail = n
	}
}

func (dh *DetailedHistory) NavigateNext() bool {
	if dh.Current != nil && dh.Current.Next != nil {
		dh.Current = dh.Current.Next
		return true
	}
	return false
}

func (dh *DetailedHistory) NavigatePrev() bool {
	if dh.Current != nil && dh.Current.Prev != nil {
		dh.Current = dh.Current.Prev
		return true
	}
	return false
}

func (dh *DetailedHistory) DisplayCurrent() {
	if dh.Current == nil {
		fmt.Println("Tidak ada rekam medis detail.")
		return
	}
	fmt.Println("\n=== REKAM MEDIS DETAIL ===")
	fmt.Printf("Tanggal: %s\n", dh.Current.Date.Format("02/01/2006 15:04"))
	fmt.Printf("Dokter: %s\n", dh.Current.DoctorName)
	fmt.Printf("Diagnosis: %s\n", dh.Current.Diagnosis)
	fmt.Printf("Resep: %s\n", dh.Current.Prescription)
	fmt.Printf("Catatan: %s\n", dh.Current.Notes)
}

// ---------- Stack (Undo/Redo operations for ADD_RECORD) ----------
type OperationLog struct {
	Action    string // "ADD_RECORD"
	PatientID string
	Data      MedicalRecord // store value
	Timestamp time.Time
	Next      *OperationLog
}

type Stack struct {
	Top  *OperationLog
	Size int
}

func NewStack() *Stack { return &Stack{} }

func (s *Stack) Push(action, pid string, data MedicalRecord) {
	n := &OperationLog{
		Action:    action,
		PatientID: pid,
		Data:      data,
		Timestamp: time.Now(),
		Next:      s.Top,
	}
	s.Top = n
	s.Size++
}

func (s *Stack) Pop() *OperationLog {
	if s.Top == nil {
		return nil
	}
	n := s.Top
	s.Top = n.Next
	n.Next = nil
	s.Size--
	return n
}

func (s *Stack) IsEmpty() bool {
	return s.Top == nil
}

func (s *Stack) Display(limit int) {
	if s.Top == nil {
		fmt.Println("Tidak ada riwayat operasi.")
		return
	}
	fmt.Println("\n=== RIWAYAT OPERASI (TOP) ===")
	i := 1
	cur := s.Top
	for cur != nil && i <= limit {
		fmt.Printf("%d. %s | pasien: %s | %s\n", i, cur.Action, cur.PatientID, cur.Timestamp.Format("15:04:05"))
		cur = cur.Next
		i++
	}
}

// ---------- Prescription & Pickup Queues ----------
type Prescription struct {
	QueueNo     int
	PatientID   string
	PatientName string
	DoctorName  string
	Diagnosis   string
	Medicine    string
	CreatedAt   time.Time
}

type PrescriptionQueue struct {
	items   []Prescription
	counter int
}

func NewPrescriptionQueue() *PrescriptionQueue {
	return &PrescriptionQueue{items: make([]Prescription, 0)}
}

func (pq *PrescriptionQueue) Enqueue(p Prescription) int {
	pq.counter++
	p.QueueNo = pq.counter
	pq.items = append(pq.items, p)
	return p.QueueNo
}

func (pq *PrescriptionQueue) Dequeue() (Prescription, bool) {
	if len(pq.items) == 0 {
		return Prescription{}, false
	}
	p := pq.items[0]
	pq.items = pq.items[1:]
	return p, true
}

func (pq *PrescriptionQueue) PeekAll() []Prescription {
	return pq.items
}

func (pq *PrescriptionQueue) IsEmpty() bool {
	return len(pq.items) == 0
}

type PickupEntry struct {
	QueueNo     int
	PatientID   string
	PatientName string
	Medicine    string
	Quantity    int
	TotalCost   float64
	CreatedAt   time.Time
}

type PickupQueue struct {
	items   []PickupEntry
	counter int
}

func NewPickupQueue() *PickupQueue { return &PickupQueue{items: make([]PickupEntry, 0)} }

func (pq *PickupQueue) Enqueue(e PickupEntry) int {
	pq.counter++
	e.QueueNo = pq.counter
	pq.items = append(pq.items, e)
	return e.QueueNo
}

func (pq *PickupQueue) Dequeue() (PickupEntry, bool) {
	if len(pq.items) == 0 {
		return PickupEntry{}, false
	}
	e := pq.items[0]
	pq.items = pq.items[1:]
	return e, true
}

func (pq *PickupQueue) PeekAll() []PickupEntry {
	return pq.items
}

func (pq *PickupQueue) IsEmpty() bool {
	return len(pq.items) == 0
}

// ========================= CLINIC SYSTEM =========================
type ClinicSystem struct {
	Queue             *Queue
	Patients          map[string]Patient
	MedicalHistories  map[string]*MedicalHistory
	DetailedHistories map[string]*DetailedHistory
	Prescriptions     *PrescriptionQueue
	Pickup            *PickupQueue
	UndoStack         *Stack
	RedoStack         *Stack
	CurrentUser       string
	CurrentRole       string
}

func NewClinicSystem() *ClinicSystem {
	return &ClinicSystem{
		Queue:             NewQueue(),
		Patients:          make(map[string]Patient),
		MedicalHistories:  make(map[string]*MedicalHistory),
		DetailedHistories: make(map[string]*DetailedHistory),
		Prescriptions:     NewPrescriptionQueue(),
		Pickup:            NewPickupQueue(),
		UndoStack:         NewStack(),
		RedoStack:         NewStack(),
	}
}

// ========================= HELPERS =========================
var reader = bufio.NewReader(os.Stdin)

func readLine(prompt string) string {
	fmt.Print(prompt)
	text, _ := reader.ReadString('\n')
	return strings.TrimSpace(text)
}

func parseIntSafe(s string) int {
	i, _ := strconv.Atoi(strings.TrimSpace(s))
	return i
}

func parseFloatSafe(s string) float64 {
	f, _ := strconv.ParseFloat(strings.TrimSpace(s), 64)
	return f
}

// ========================= INITIAL SAMPLE DATA =========================
func (cs *ClinicSystem) SeedSampleData() {
	// sample patients
	p1 := Patient{ID: "P001", Name: "Ahmad Santoso", Age: 30, Address: "Jl. Merdeka 1", Phone: "081234567890", Insurance: "BPJS", RegistrationTime: time.Now()}
	p2 := Patient{ID: "P002", Name: "Siti Nurhaliza", Age: 27, Address: "Jl. Melati 2", Phone: "081234567891", Insurance: "Mandiri Inhealth", RegistrationTime: time.Now()}
	p3 := Patient{ID: "P003", Name: "Budi Hartono", Age: 45, Address: "Jl. Kenangan 3", Phone: "081234567892", Insurance: "Umum", RegistrationTime: time.Now()}

	cs.Patients[p1.ID] = p1
	cs.Patients[p2.ID] = p2
	cs.Patients[p3.ID] = p3

	// add some to queue
	cs.Queue.Enqueue(p1)
	cs.Queue.Enqueue(p2)

	// sample medical history for p1
	mh := NewMedicalHistory()
	mh.AddRecord(MedicalRecord{
		Date:         time.Now().AddDate(0, -1, 0),
		DoctorName:   "Dr. Susanto",
		Diagnosis:    "Flu ringan",
		Prescription: "Paracetamol 3x1",
		Notes:        "Istirahat cukup",
	})
	cs.MedicalHistories[p1.ID] = mh

	// detailed history
	dh := NewDetailedHistory()
	dh.AddRecord(DetailedRecord{
		Date:         time.Now().AddDate(0, -1, 0),
		DoctorName:   "Dr. Susanto",
		Diagnosis:    "Flu ringan",
		Prescription: "Paracetamol 3x1",
		Notes:        "Minum air putih",
	})
	cs.DetailedHistories[p1.ID] = dh
}

// ========================= AUTH & MENUS =========================
func (cs *ClinicSystem) Login(username, role string) {
	cs.CurrentUser = username
	cs.CurrentRole = role
	fmt.Printf("\n✓ Login berhasil sebagai %s (%s)\n", username, role)
}

func showLoginMenu(cs *ClinicSystem) {
	for {
		fmt.Println("\n==============================================")
		fmt.Println("   SISTEM ANTRIAN PELAYANAN KLINIK - LOGIN")
		fmt.Println("==============================================")
		fmt.Println("Pilih role:")
		fmt.Println("1. ADMIN")
		fmt.Println("2. RECEPTIONIST")
		fmt.Println("3. DOCTOR")
		fmt.Println("4. PHARMACIST")
		fmt.Println("0. EXIT")
		choice := readLine("Pilihan: ")
		switch choice {
		case "1":
			cs.Login("Admin", "ADMIN")
		case "2":
			cs.Login("Receptionist", "RECEPTIONIST")
		case "3":
			cs.Login("Dr. Susanto", "DOCTOR")
		case "4":
			cs.Login("Pharmacist", "PHARMACIST")
		case "0":
			fmt.Println("Keluar program. Sampai jumpa.")
			os.Exit(0)
		default:
			fmt.Println("Pilihan tidak valid.")
			continue
		}
		// on successful login, show role menus until logout
		cs.RoleLoop()
	}
}

func (cs *ClinicSystem) RoleLoop() {
	for {
		cs.ShowMainMenu()
		choice := readLine("\nPilih menu: ")
		if choice == "0" {
			// logout: reset user & role, return to login menu
			cs.CurrentUser = ""
			cs.CurrentRole = ""
			fmt.Println("✓ Logout berhasil. Kembali ke menu login.")
			return
		}
		cs.HandleMenuChoice(choice)
	}
}

func (cs *ClinicSystem) ShowMainMenu() {
	fmt.Println("\n==============================================")
	fmt.Printf("User: %s | Role: %s\n", cs.CurrentUser, cs.CurrentRole)
	fmt.Println("==============================================")
	switch cs.CurrentRole {
	case "ADMIN":
		fmt.Println("1. Dashboard Antrian (Real-time)")
		fmt.Println("2. Laporan Harian / Mingguan / Bulanan")
		fmt.Println("3. Monitoring Kinerja & Logs")
		fmt.Println("4. Lihat Riwayat Kunjungan (read-only)")
		fmt.Println("5. Lihat Rekam Medis Detail (read-only)")
		fmt.Println("0. Logout")
	case "RECEPTIONIST":
		fmt.Println("1. Daftar Pasien Baru ke Antrian")
		fmt.Println("2. Lihat Antrian")
		fmt.Println("3. Update Data Pasien")
		fmt.Println("4. Cetak Nomor Antrian")
		fmt.Println("5. Estimasi Waktu Tunggu (menit)")
		fmt.Println("6. Reschedule / Pindah Antrian (by queue no)")
		fmt.Println("0. Logout")
	case "DOCTOR":
		fmt.Println("1. Panggil Pasien Berikutnya (dokter sendiri)")
		fmt.Println("2. Lihat Riwayat Kunjungan (single linked list)")
		fmt.Println("3. Navigasi Rekam Medis Detail (double linked list)")
		fmt.Println("4. Input Diagnosa & Resep (masuk ke antrian resep)")
		fmt.Println("5. Undo (ADD_RECORD)")
		fmt.Println("6. Redo (ADD_RECORD)")
		fmt.Println("0. Logout")
	case "PHARMACIST":
		fmt.Println("1. Lihat Daftar Resep Menunggu")
		fmt.Println("2. Proses Resep (ambil dari antrian resep -> buat pickup entry)")
		fmt.Println("3. Lihat Antrian Pengambilan Obat")
		fmt.Println("4. Panggil Pasien Ambil Obat")
		fmt.Println("0. Logout")
	default:
		fmt.Println("Role tidak dikenali. Logout.")
	}
}

func (cs *ClinicSystem) HandleMenuChoice(choice string) {
	switch cs.CurrentRole {
	case "ADMIN":
		cs.handleAdminMenu(choice)
	case "RECEPTIONIST":
		cs.handleReceptionistMenu(choice)
	case "DOCTOR":
		cs.handleDoctorMenu(choice)
	case "PHARMACIST":
		cs.handlePharmacistMenu(choice)
	default:
		fmt.Println("Role tidak dikenali.")
	}
}

// ========================= ADMIN HANDLERS =========================
func (cs *ClinicSystem) handleAdminMenu(choice string) {
	switch choice {
	case "1":
		fmt.Println("\n=== DASHBOARD ANTRIAN ===")
		fmt.Printf("Total Antrian Saat Ini: %d\n", len(cs.Queue.nodes))
		fmt.Printf("Pasien Terdaftar: %d\n", len(cs.Patients))
		cs.Queue.Print()
	case "2":
		fmt.Println("\n=== LAPORAN SEDERHANA ===")
		fmt.Printf("Tanggal: %s\n", time.Now().Format("02/01/2006"))
		// simple report: number served approx = prescriptions + dequeued (we don't store completed count separately here)
		fmt.Printf("Total Antrian Dikeluarkan (counter): %d\n", cs.Queue.counter)
	case "3":
		fmt.Println("\n=== MONITORING KINERJA ===")
		fmt.Println("Fitur monitoring detail dapat ditingkatkan (response times, avg wait).")
	case "4":
		fmt.Println("\n=== RIWAYAT KUNJUNGAN (READ-ONLY) ===")
		id := readLine("Masukkan ID Pasien untuk melihat riwayat (contoh P001): ")
		if mh, ok := cs.MedicalHistories[id]; ok {
			mh.Display()
		} else {
			fmt.Println("Tidak ada riwayat untuk pasien ini.")
		}
	case "5":
		fmt.Println("\n=== REKAM MEDIS DETAIL (READ-ONLY) ===")
		id := readLine("Masukkan ID Pasien untuk navigasi detail: ")
		if dh, ok := cs.DetailedHistories[id]; ok {
			dh.DisplayCurrent()
			for {
				cmd := strings.ToLower(readLine("[n]ext, [p]rev, [q]uit: "))
				if cmd == "n" {
					if !dh.NavigateNext() {
						fmt.Println("Sudah di akhir rekam medis.")
					}
					dh.DisplayCurrent()
				} else if cmd == "p" {
					if !dh.NavigatePrev() {
						fmt.Println("Sudah di awal rekam medis.")
					}
					dh.DisplayCurrent()
				} else if cmd == "q" {
					break
				}
			}
		} else {
			fmt.Println("Tidak ada rekam medis detail untuk pasien ini.")
		}
	default:
		fmt.Println("Pilihan admin tidak valid.")
	}
}

// ========================= RECEPTIONIST HANDLERS =========================
func (cs *ClinicSystem) handleReceptionistMenu(choice string) {
	switch choice {
	case "1":
		fmt.Println("\n=== DAFTAR PASIEN BARU KE ANTRIAN ===")
		id := readLine("ID Pasien (unik, contoh P004): ")
		if id == "" {
			fmt.Println("ID tidak boleh kosong.")
			return
		}
		if _, exists := cs.Patients[id]; exists {
			fmt.Println("ID pasien sudah terdaftar. Anda bisa update demografi atau langsung enqueue.")
		}
		name := readLine("Nama pasien: ")
		ageStr := readLine("Umur: ")
		age := parseIntSafe(ageStr)
		addr := readLine("Alamat: ")
		phone := readLine("Telepon: ")
		ins := readLine("Asuransi/BPJS: ")

		p := Patient{
			ID:               id,
			Name:             name,
			Age:              age,
			Address:          addr,
			Phone:            phone,
			Insurance:        ins,
			RegistrationTime: time.Now(),
		}
		// store patient record (if new or updating)
		cs.Patients[id] = p
		// enqueue
		num := cs.Queue.Enqueue(p)
		// reflect queue number into stored patient struct
		tmp := cs.Patients[id]
		tmp.QueueNo = num
		cs.Patients[id] = tmp

		fmt.Printf("✓ Pasien %s (ID:%s) berhasil didaftarkan ke antrian. Nomor: %d\n", p.Name, p.ID, num)

	case "2":
		cs.Queue.Print()

	case "3":
		// Update Data Pasien by ID
		fmt.Println("\n=== UPDATE DATA PASIEN ===")
		id := readLine("Masukkan ID Pasien: ")
		p, ok := cs.Patients[id]
		if !ok {
			fmt.Println("Pasien tidak ditemukan.")
			return
		}
		fmt.Println("Data Lama:")
		fmt.Printf("Nama: %s\nUmur: %d\nAlamat: %s\nTelepon: %s\nAsuransi: %s\n", p.Name, p.Age, p.Address, p.Phone, p.Insurance)
		fmt.Println("Masukkan data baru (kosongkan untuk tidak mengubah):")
		newName := readLine("Nama baru: ")
		if newName != "" {
			p.Name = newName
		}
		newAgeStr := readLine("Umur baru: ")
		if newAgeStr != "" {
			p.Age = parseIntSafe(newAgeStr)
		}
		newAddr := readLine("Alamat baru: ")
		if newAddr != "" {
			p.Address = newAddr
		}
		newPhone := readLine("Telepon baru: ")
		if newPhone != "" {
			p.Phone = newPhone
		}
		newIns := readLine("Asuransi baru/BPJS: ")
		if newIns != "" {
			p.Insurance = newIns
		}
		cs.Patients[id] = p
		fmt.Println("✓ Data pasien berhasil diperbarui.")

	case "4":
		// Cetak Nomor Antrian by ID
		fmt.Println("\n=== CETAK NOMOR ANTRIAN ===")
		id := readLine("Masukkan ID Pasien: ")
		p, ok := cs.Patients[id]
		if !ok {
			fmt.Println("Pasien tidak ditemukan.")
			return
		}
		// find in queue
		found := false
		for _, node := range cs.Queue.nodes {
			if node.ID == id {
				fmt.Println("===================================")
				fmt.Printf("   NOMOR ANTRIAN KLINIK\n")
				fmt.Printf("   Nama: %s\n", p.Name)
				fmt.Printf("   ID: %s\n", p.ID)
				fmt.Printf("   Nomor Antri: %d\n", node.QueueNo)
				fmt.Println("===================================")
				found = true
				break
			}
		}
		if !found {
			fmt.Println("Pasien tidak memiliki nomor antrian aktif.")
		}

	case "5":
		// Estimasi waktu tunggu per dokter (we don't have per-doctor queues; assume avg 10 minutes)
		fmt.Println("\n=== ESTIMASI WAKTU TUNGGU ===")
		avgStr := readLine("Masukkan estimasi menit per pasien (mis. 10): ")
		avg := parseIntSafe(avgStr)
		if avg <= 0 {
			avg = 10
		}
		// count waiting
		waiting := len(cs.Queue.nodes)
		fmt.Printf("Perkiraan waktu tunggu: ~%d menit (untuk %d pasien di depan)\n", waiting*avg, waiting)

	case "6":
		// Reschedule by queue number: change queue position to end or remove & re-enqueue
		fmt.Println("\n=== RESCHEDULE ANTRIAN ===")
		noStr := readLine("Masukkan nomor antrian yang ingin dipindah (queue no): ")
		no := parseIntSafe(noStr)
		if no <= 0 {
			fmt.Println("Nomor antrian invalid.")
			return
		}
		// find and requeue to end
		var foundPatient *Patient
		for i := range cs.Queue.nodes {
			if cs.Queue.nodes[i].QueueNo == no {
				// remove
				foundPatient = &cs.Queue.nodes[i]
				cs.Queue.nodes = append(cs.Queue.nodes[:i], cs.Queue.nodes[i+1:]...)
				break
			}
		}
		if foundPatient == nil {
			fmt.Println("Nomor antrian tidak ditemukan.")
			return
		}
		// re-enqueue to end
		newNo := cs.Queue.Enqueue(*foundPatient)
		// update stored patient
		p := cs.Patients[foundPatient.ID]
		p.QueueNo = newNo
		cs.Patients[p.ID] = p
		fmt.Printf("✓ Nomor antrian %d dipindah ke posisi akhir dengan nomor baru %d\n", no, newNo)

	default:
		fmt.Println("Pilihan receptionist tidak valid.")
	}
}

// ========================= DOCTOR HANDLERS =========================
func (cs *ClinicSystem) handleDoctorMenu(choice string) {
	switch choice {
	case "1":
		fmt.Println("\n=== PANGGIL PASIEN BERIKUTNYA (dokter) ===")
		// In this simple model, doctors are not separated; just dequeue next patient
		p, ok := cs.Queue.Dequeue()
		if !ok {
			fmt.Println("Tidak ada pasien dalam antrian.")
			return
		}
		// update stored patient: queue no reset to 0 since being served
		tmp := cs.Patients[p.ID]
		tmp.QueueNo = 0
		cs.Patients[p.ID] = tmp

		fmt.Printf("✓ Memanggil pasien: %s (ID:%s)\n", p.Name, p.ID)

	case "2":
		fmt.Println("\n=== LIHAT RIWAYAT KUNJUNGAN ===")
		id := readLine("Masukkan ID Pasien: ")
		if mh, ok := cs.MedicalHistories[id]; ok {
			mh.Display()
		} else {
			fmt.Println("Tidak ada riwayat untuk pasien ini.")
		}

	case "3":
		fmt.Println("\n=== NAVIGASI REKAM MEDIS DETAIL ===")
		id := readLine("Masukkan ID Pasien: ")
		if dh, ok := cs.DetailedHistories[id]; ok {
			dh.DisplayCurrent()
			for {
				cmd := strings.ToLower(readLine("[n]ext, [p]rev, [q]uit: "))
				if cmd == "n" {
					if !dh.NavigateNext() {
						fmt.Println("Sudah di akhir rekam medis.")
					}
					dh.DisplayCurrent()
				} else if cmd == "p" {
					if !dh.NavigatePrev() {
						fmt.Println("Sudah di awal rekam medis.")
					}
					dh.DisplayCurrent()
				} else if cmd == "q" {
					break
				}
			}
		} else {
			fmt.Println("Tidak ada rekam medis detail untuk pasien ini.")
		}

	case "4":
		// Input Diagnosa & Resep, push to MedicalHistory, DetailedHistory and PrescriptionQueue
		fmt.Println("\n=== INPUT DIAGNOSA & RESEP ===")
		pid := readLine("Masukkan ID Pasien: ")
		p, ok := cs.Patients[pid]
		if !ok {
			fmt.Println("Pasien tidak terdaftar.")
			return
		}
		diag := readLine("Diagnosis: ")
		resep := readLine("Resep/Obat (jika lebih dari 1 pisahkan dengan koma): ")
		notes := readLine("Catatan tambahan: ")

		rec := MedicalRecord{
			Date:         time.Now(),
			DoctorName:   cs.CurrentUser,
			Diagnosis:    diag,
			Prescription: resep,
			Notes:        notes,
		}
		// add to medical history
		if _, ok := cs.MedicalHistories[pid]; !ok {
			cs.MedicalHistories[pid] = NewMedicalHistory()
		}
		cs.MedicalHistories[pid].AddRecord(rec)

		// add to detailed history
		if _, ok := cs.DetailedHistories[pid]; !ok {
			cs.DetailedHistories[pid] = NewDetailedHistory()
		}
		cs.DetailedHistories[pid].AddRecord(DetailedRecord{
			Date:         rec.Date,
			DoctorName:   rec.DoctorName,
			Diagnosis:    rec.Diagnosis,
			Prescription: rec.Prescription,
			Notes:        rec.Notes,
		})

		// push to undo stack (ADD_RECORD)
		cs.UndoStack.Push("ADD_RECORD", pid, rec)
		// clear redo stack after new op
		cs.RedoStack = NewStack()

		// create prescription entry if resep not empty
		if strings.TrimSpace(resep) != "" {
			pres := Prescription{
				PatientID:   pid,
				PatientName: p.Name,
				DoctorName:  cs.CurrentUser,
				Diagnosis:   diag,
				Medicine:    resep,
				CreatedAt:   time.Now(),
			}
			no := cs.Prescriptions.Enqueue(pres)
			fmt.Printf("✓ Resep dimasukkan ke antrian resep. No.Resep: %d\n", no)
		}

		fmt.Println("✓ Rekam medis berhasil ditambahkan.")

	case "5":
		// Undo
		fmt.Println("\n=== UNDO (ADD_RECORD) ===")
		if cs.UndoStack.IsEmpty() {
			fmt.Println("Tidak ada operasi untuk di-undo.")
			return
		}
		log := cs.UndoStack.Pop()
		if log == nil {
			fmt.Println("Gagal mengambil log undo.")
			return
		}
		if log.Action == "ADD_RECORD" {
			pid := log.PatientID
			// remove last record from medical history
			if mh, ok := cs.MedicalHistories[pid]; ok {
				removed := mh.RemoveLastRecord()
				if removed != nil {
					// also remove last detailed record
					if dh, ok := cs.DetailedHistories[pid]; ok {
						if dh.Tail != nil {
							if dh.Tail.Prev != nil {
								dh.Tail = dh.Tail.Prev
								dh.Tail.Next = nil
							} else {
								// only one node
								dh.Head = nil
								dh.Tail = nil
								dh.Current = nil
							}
						}
					}
					// push to redo
					cs.RedoStack.Push(log.Action, pid, *removed)
					fmt.Println("✓ Undo berhasil: penambahan rekam medis dibatalkan.")
				} else {
					fmt.Println("Tidak ada record untuk di-undo.")
				}
			} else {
				fmt.Println("Riwayat pasien tidak ditemukan untuk undo.")
			}
		} else {
			fmt.Println("Undo action tidak dikenali.")
		}

	case "6":
		// Redo
		fmt.Println("\n=== REDO (ADD_RECORD) ===")
		if cs.RedoStack.IsEmpty() {
			fmt.Println("Tidak ada operasi untuk di-redo.")
			return
		}
		log := cs.RedoStack.Pop()
		if log == nil {
			fmt.Println("Gagal mengambil log redo.")
			return
		}
		if log.Action == "ADD_RECORD" {
			pid := log.PatientID
			rec := log.Data
			// re-add
			if _, ok := cs.MedicalHistories[pid]; !ok {
				cs.MedicalHistories[pid] = NewMedicalHistory()
			}
			cs.MedicalHistories[pid].AddRecord(rec)
			// detailed
			if _, ok := cs.DetailedHistories[pid]; !ok {
				cs.DetailedHistories[pid] = NewDetailedHistory()
			}
			cs.DetailedHistories[pid].AddRecord(DetailedRecord{
				Date:         rec.Date,
				DoctorName:   rec.DoctorName,
				Diagnosis:    rec.Diagnosis,
				Prescription: rec.Prescription,
				Notes:        rec.Notes,
			})
			// push back to undo
			cs.UndoStack.Push("ADD_RECORD", pid, rec)
			fmt.Println("✓ Redo berhasil: rekam medis dikembalikan.")
		} else {
			fmt.Println("Redo action tidak dikenali.")
		}

	default:
		fmt.Println("Pilihan dokter tidak valid.")
	}
}

// ========================= PHARMACIST HANDLERS =========================
func (cs *ClinicSystem) handlePharmacistMenu(choice string) {
	switch choice {
	case "1":
		fmt.Println("\n=== DAFTAR RESEP MENUNGGU ===")
		items := cs.Prescriptions.PeekAll()
		if len(items) == 0 {
			fmt.Println("Tidak ada resep menunggu.")
			return
		}
		for _, r := range items {
			fmt.Printf("No.%d | Pasien: %s (%s) | Dokter: %s | Obat: %s | Waktu: %s\n",
				r.QueueNo, r.PatientName, r.PatientID, r.DoctorName, r.Medicine, r.CreatedAt.Format("02/01/2006 15:04"))
		}

	case "2":
		// Process prescription: dequeue from prescription queue and create pickup entry
		fmt.Println("\n=== PROSES RESEP (APOTEKER) ===")
		pres, ok := cs.Prescriptions.Dequeue()
		if !ok {
			fmt.Println("Tidak ada resep untuk diproses.")
			return
		}
		fmt.Printf("Memproses resep No.%d untuk pasien %s (%s). Obat: %s\n", pres.QueueNo, pres.PatientName, pres.PatientID, pres.Medicine)
		// input medication details / qty / cost
		med := readLine("Nama obat yang diberikan (kosong = gunakan resep): ")
		if med == "" {
			med = pres.Medicine
		}
		qtyStr := readLine("Jumlah (qty): ")
		qty := parseIntSafe(qtyStr)
		if qty <= 0 {
			qty = 1
		}
		costStr := readLine("Total biaya obat (mis. 15000.50): ")
		cost := parseFloatSafe(costStr)
		// create pickup entry and enqueue into pickup queue
		entry := PickupEntry{
			PatientID:   pres.PatientID,
			PatientName: pres.PatientName,
			Medicine:    med,
			Quantity:    qty,
			TotalCost:   cost,
			CreatedAt:   time.Now(),
		}
		no := cs.Pickup.Enqueue(entry)
		fmt.Printf("✓ Resep diproses. Pasien dimasukkan ke antrian pengambilan obat No.%d\n", no)

	case "3":
		// View pickup queue
		fmt.Println("\n=== ANTRIAN PENGAMBILAN OBAT ===")
		items := cs.Pickup.PeekAll()
		if len(items) == 0 {
			fmt.Println("Belum ada pasien untuk pengambilan obat.")
			return
		}
		for _, e := range items {
			fmt.Printf("No.%d | Pasien: %s (%s) | Obat: %s | Qty: %d | Total: %.2f\n",
				e.QueueNo, e.PatientName, e.PatientID, e.Medicine, e.Quantity, e.TotalCost)
		}

	case "4":
		// Call patient to pick up medicine (dequeue pickup)
		fmt.Println("\n=== PANGGIL PASIEN AMBIL OBAT ===")
		entry, ok := cs.Pickup.Dequeue()
		if !ok {
			fmt.Println("Tidak ada pasien siap mengambil obat.")
			return
		}
		fmt.Printf("✓ Panggil: %s (ID:%s) untuk mengambil obat: %s | Qty:%d | Total: %.2f\n",
			entry.PatientName, entry.PatientID, entry.Medicine, entry.Quantity, entry.TotalCost)
		// optionally print receipt (simple)
		fmt.Println("----- STRUK PEMBAYARAN -----")
		fmt.Printf("Pasien: %s\nObat: %s\nJumlah: %d\nTotal: %.2f\n", entry.PatientName, entry.Medicine, entry.Quantity, entry.TotalCost)
		fmt.Println("----------------------------")

	default:
		fmt.Println("Pilihan pharmacist tidak valid.")
	}
}

// ========================= BOOTSTRAP & MAIN =========================
func main() {
	cs := NewClinicSystem()
	cs.SeedSampleData()
	showLoginMenu(cs)
}
