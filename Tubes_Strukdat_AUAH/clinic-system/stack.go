// stack.go
package main

import (
	"fmt"
	"time"
)

// ==================== STACK ADT (Undo/Redo) ====================

// Stack implements a LIFO stack for undo/redo operations
type Stack struct {
	Top  *OperationLog
	Size int
}

// NewStack creates a new empty stack
func NewStack() *Stack {
	return &Stack{}
}

// Push adds a new operation to the top of the stack
func (s *Stack) Push(action string, data interface{}) {
	newNode := &OperationLog{
		Action:    action,
		Data:      data,
		Timestamp: time.Now(),
		Next:      s.Top,
	}
	s.Top = newNode
	s.Size++
}

// Pop removes and returns the top operation from the stack
func (s *Stack) Pop() *OperationLog {
	if s.Top == nil {
		return nil
	}

	node := s.Top
	s.Top = s.Top.Next
	s.Size--
	return node
}

// Peek returns the top operation without removing it
func (s *Stack) Peek() *OperationLog {
	return s.Top
}

// IsEmpty checks if the stack is empty
func (s *Stack) IsEmpty() bool {
	return s.Top == nil
}

// Display shows the recent operations in the stack (up to 5)
func (s *Stack) Display() {
	if s.IsEmpty() {
		fmt.Println("\nTidak ada riwayat operasi")
		return
	}

	fmt.Println("\n=== RIWAYAT OPERASI ===")
	current := s.Top
	count := 1
	for current != nil && count <= 5 {
		fmt.Printf("%d. %s - %s\n", count, current.Action, current.Timestamp.Format("15:04:05"))
		current = current.Next
		count++
	}
}
