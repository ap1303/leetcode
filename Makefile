All: LCP ATN LLS LP zTransform

LCP:
		gcc -Wall -g -o longestCommonPrefix longestCommonPrefix.c

ATN:
		gcc -Wall -g -o addTwoNumbers addTwoNumbers.c

LLS:
		gcc -Wall -g -o lengthOfLongestSubstring lengthOfLongestSubstring.c

LP:
		gcc -Wall -g -o longestPalindrome longestPalindrome.c

zTransform:
		gcc -Wall -g -o zTransform zTransform.c

clean:
		rm -rf longestCommonPrefix
		rm -rf addTwoNumbers
		rm -rf lengthOfLongestSubstring
		rm -rf longestPalindrome
		rm -rf zTransform
