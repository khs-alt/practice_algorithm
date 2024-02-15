package main

func Solution(my_string string, overwrite_string string, s int) string {
	s1 := []byte(my_string) //string is immutable so it chang byte array for mutable
	s2 := []byte(overwrite_string)
	n := len(s2)
	for i := 0; i < n; i++ {
		s1[s+i] = s2[i]
	}
	return string(s1)
}
