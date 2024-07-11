import java.util.*;
class Solution {
  public boolean isAnagram(String s, String t) {
        HashMap<Character,Integer> s1 =new HashMap<>();
        HashMap<Character,Integer> t1 =new HashMap<>();
        for (char c : s.toCharArray()) {
            if (s1.containsKey(c)){
                int count = s1.get(c);
                s1.put(c,count+1);
            }
            else{
                s1.put(c,1);
            }
        }
        for (char c : t.toCharArray()) {
            if (t1.containsKey(c)){
                int count = t1.get(c);
                t1.put(c,count+1);
            }
            else{
                t1.put(c,1);
            }
        }
        return s1.equals(t1);
    }
}
