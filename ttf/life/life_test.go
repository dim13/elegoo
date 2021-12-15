package life

import "testing"

func TestNext(t *testing.T) {
	st := []struct {
		a, n int
		on   bool
	}{
		{0, 0, false},
		{0, 1, false},
		{0, 2, false},
		{0, 3, true},
		{0, 4, false},
		{0, 5, false},
		{0, 6, false},
		{0, 7, false},
		{0, 8, false},
		{1, 0, false},
		{1, 1, false},
		{1, 2, true},
		{1, 3, true},
		{1, 4, false},
		{1, 5, false},
		{1, 6, false},
		{1, 7, false},
		{1, 8, false},
	}
	for _, x := range st {
		on := next(x.a, x.n)
		if on != x.on {
			t.Error(x, on)
		}
	}
}
