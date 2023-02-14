class Solution {
    public String addBinary(String a, String b) {
        if (a.length() < b.length()){
            a = a + b;
            b = a.substring(0, a.length() - b.length());
            a = a.substring(b.length());
        }
        int diff = a.length() - b.length();
        for (int i = 0; i < diff; i++){
            b = "0" + b;
        }
        char[] summend = a.toCharArray(), addend = b.toCharArray();
        int carry = 0;
        for (int i = summend.length - 1; i >= 0; i--){
            char c1 = summend[i], c2 = addend[i];
            int result = (c1 - '0') + (c2 - '0') + carry;
            carry = result / 2;
            summend[i] = (char)((result % 2) + '0');
        }
        String ans = String.valueOf(summend);
        if (carry == 1){
            ans = "1" + ans;
        }
        return ans;
    }
}