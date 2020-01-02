package geektime

func bubble_1(arr []int) []int {
	ret := make([]int, len(arr))
	copy(ret, arr)
	for i := range ret {
		for j := range ret[i:] {
			j = i + j
			if ret[i] > ret[j] {
				tmp := ret[i]
				ret[i] = ret[j]
				ret[j] = tmp
			}
		}
	}
	return ret
}

func bubble_2(arr []int) []int {
	ret := make([]int, len(arr))
	copy(ret, arr)
	for i := range ret {
		flag := false
		for j := range ret[i:] {
			j = i + j
			if ret[i] > ret[j] {
				flag = true
				tmp := ret[i]
				ret[i] = ret[j]
				ret[j] = tmp
			}
		}
		if !flag {
			break
		}
	}
	return ret
}

func insert(arr []int) []int {
	ret := make([]int, len(arr))
	copy(ret, arr)
	for i := 1; i < len(ret); i++ {
		val := ret[i]
		j := i - 1
		for ; j >= 0; j-- {
			if ret[j] > val {
				ret[j+1] = ret[j]
			} else {
				break
			}
		}
		ret[j+1] = val
	}
	return ret
}

func selection(arr []int) []int {
	ret := make([]int, len(arr))
	copy(ret, arr)
	for i := range ret {
		min := i
		for j := range ret[i:] {
			j = i + j
			if ret[min] > ret[j] {
				min = j
			}
		}
		tmp := ret[min]
		ret[min] = ret[i]
		ret[i] = tmp
	}
	return ret
}
