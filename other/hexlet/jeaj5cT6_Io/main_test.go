package main

import (
	"testing"
)

func TestGetResult(t *testing.T) {
	tests := []struct {
		a, b, aP, bP, expected int
	}{
		{1, 2, 1, 2, PrizeBig},   // Точный счёт
		{1, 2, 0, 1, PrizeNo},    // Не угадал
		{1, 1, 2, 2, PrizeSmall}, // Ничья
		{3, 1, 2, 1, PrizeSmall}, // Исход
		{0, 0, 1, 1, PrizeSmall}, // Ничья
		{1, 0, 0, 1, PrizeNo},    // Не угадал
	}

	for _, tt := range tests {
		t.Run("", func(t *testing.T) {
			result := GetResult(tt.a, tt.b, tt.aP, tt.bP)
			if result != tt.expected {
				t.Errorf("GetResult(%d, %d, %d, %d) = %d; expected %d",
					tt.a, tt.b, tt.aP, tt.bP, result, tt.expected)
			}
		})
	}
}
