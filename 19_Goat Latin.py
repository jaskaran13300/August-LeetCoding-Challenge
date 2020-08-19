def isVovel(ch):
    return ch=="a" or ch=="e" or ch=="i" or ch=="o" or ch=="u" or ch=="A" or ch=="E" or ch=="I" or ch=="O" or ch=="U"
class Solution:
    def toGoatLatin(self, S: str) -> str:
        appendLast="ma"
        
        words=S.split(' ')
        ans=""
        for s in words:
            appendLast=appendLast+"a"
            if isVovel(s[0]):
                ans=ans+s+appendLast+" "
            else:
                ans=ans+s[1:]+s[0]+appendLast+" "
        return ans[:-1]
