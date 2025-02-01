class Solution {
    public String findValidPair(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        for(char c : s.toCharArray()) {
            if(mp.containsKey(c)) {
                mp.put(c, mp.get(c)+1);
            } else {
                mp.put(c, 1);
            }
        }
        
        for(int i = 1; i < s.toCharArray().length; i++) {
            if(s.charAt(i) != s.charAt(i-1)) {
                if((mp.get(s.charAt(i)) == (s.charAt(i) - '0')) && (mp.get(s.charAt(i-1)) == (s.charAt(i-1) - '0'))) {
                    String ans = "";
                    ans += s.charAt(i-1);
                    ans += s.charAt(i);
                    
                    return ans;
                }
            }
        }
        
        return "";
    }
}