All: LCP ATN Lls

LCP:
		gcc -Wall -g -o longestCommonPrefix longestCommonPrefix.c

ATN:
		gcc -Wall -g -o addTwoNumbers addTwoNumbers.c

Lls:
		gcc -Wall -g -o lengthOfLongestSubstring lengthOfLongestSubstring.c

clean:
		rm -rf longestCommonPrefix
		rm -rf addTwoNumbers
		rm -rf lengthOfLongestSubstring
