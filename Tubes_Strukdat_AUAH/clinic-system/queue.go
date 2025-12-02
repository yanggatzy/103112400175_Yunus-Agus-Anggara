// queue.go
package main

import "fmt"

// ==================== QUEUE ADT ====================

// Queue implements a FIFO queue for patient management
type Queue struct {
	Front   *QueueNode
	Rear    *QueueNode
	Count   int
	NextNum int
}

// NewQueue creates a new empty queue
func NewQueue() *Queue {
	return &Queue{NextNum: 1}
}

// Enqueue adds a patient to the queue and returns the queue number
func (q *Queue) Enqueue(patient Patient, doctorID string) int {
	queueNum := q.NextNum
	node := &QueueNode{
		Patient:  patient,
		QueueNum: queueNum,
		Status:   "waiting",
		DoctorID: doctorID,
	}

	if q.Rear == nil {
		q.Front = node
		q.Rear = node
	} else {
		q.Rear.Next = node
		q.Rear = node
	}

	q.Count++
	q.NextNum++
	return queueNum
}

// Dequeue removes and returns the front node from the queue
func (q *Queue) Dequeue() *QueueNode {
	if q.Front == nil {
		return nil
	}

	node := q.Front
	q.Front = q.Front.Next
	if q.Front == nil {
		q.Rear = nil
	}
	q.Count--
	return node
}

// Peek returns the front node without removing it
func (q *Queue) Peek() *QueueNode {
	return q.Front
}

// IsEmpty checks if the queue is empty
func (q *Queue) IsEmpty() bool {
	return q.Front == nil
}

// GetByDoctorID finds the first waiting patient for a specific doctor
func (q *Queue) GetByDoctorID(doctorID string) *QueueNode {
	current := q.Front
	for current != nil {
		if current.DoctorID == doctorID && current.Status == "waiting" {
			return current
		}
		current = current.Next
	}
	return nil
}

// DisplayAll displays all patients in the queue
func (q *Queue) DisplayAll() {
	if q.IsEmpty() {
		fmt.Println("\nAntrian kosong")
		return
	}

	fmt.Println("\n=== DAFTAR ANTRIAN ===")
	current := q.Front
	for current != nil {
		fmt.Printf("No. %d | %s | Status: %s | Dokter: %s\n",
			current.QueueNum, current.Patient.Name, current.Status, current.DoctorID)
		current = current.Next
	}
}
