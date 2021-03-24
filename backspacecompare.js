// # Leetcode - 844. Backspace String Compare(easy)

// # Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

// # Note that after backspacing an empty text, the text will continue empty.

// # Example 1:

// # Input: S = "ab#c", T = "ad#c"
// # Output: true
// # Explanation: Both S and T become "ac".
// # Example 2:

// # Input: S = "ab##", T = "c#d#"
// # Output: true
// # Explanation: Both S and T become "".
// # Example 3:

// # Input: S = "a##c", T = "#a#c"
// # Output: true
// # Explanation: Both S and T become "c".
// # Example 4:

// # Input: S = "a#c", T = "b"
// # Output: false
// # Explanation: S becomes "c" while T becomes "b".

class Solution{
	backspacecompare(S, T) { 
		let arr1 = [];
		let arr2 = [];
		for (let i of S) {
			if (i == "#") {
				arr1.pop();
			} else {
				arr1.push(i);
			}
		}

		for (let i of T) { 
			if (i == "#") {
				arr2.pop();
			} else { 
				arr2.push(i);
			}
		}
		if (arr1.length != arr2.length) {
			console.log(arr1.length, arr2.length)
			return false;
		}
		else { 
			for (let i = 0; i < arr1.length; i++) { 
				if (arr1[i] == arr2[i]) {
					continue;
				} else { 
					return false
				}
			}
		}

		return true;
	}
}

const solution = new Solution();
console.log(solution.backspacecompare("ab##", "c#d#"))











