'''
Validate IP address
'''

class Solution:
    def validIPAddress(self, IP: str) -> str:
        v4 = re.match("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])", IP)
        if v4 and v4.group() == IP:
            return 'IPv4'
        v6 = re.match("((([0-9a-fA-F]){1,4})\\:){7}(([0-9a-fA-F]){1,4})", IP)
        if v6 and v6.group() == IP:
            return 'IPv6'
        return 'Neither'
