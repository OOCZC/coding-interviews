public class Solution {
    public String replaceSpace(StringBuffer str) {
        StringBuffer re = new StringBuffer();
        
        for (int i = 0; i < str.length(); ++i) {
            if (str.charAt(i) == ' ')
                re.append("%20");
            else
                re.append(str.charAt(i));
        }
        return re.toString();
    }
}
