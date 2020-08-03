class Solution:
    def isPalindrome(self, s: str) -> bool:
        s=s.lower()
        i,j=0,len(s)-1
        
        while(i<=j):
            ch1=s[i]
            ch2=s[j]
            if not ch1.isnumeric() and not  ch1.isalpha():
                i=i+1
                continue
            if not ch2.isnumeric() and not  ch2.isalpha():
                j=j-1
                continue
            if ch1!=ch2:
                return False
            i=i+1
            j=j-1
            
        return True
            
        
