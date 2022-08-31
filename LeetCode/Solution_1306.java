package LeetCode;

import java.text.ParseException;
import java.text.SimpleDateFormat;

public class Solution_1306 {
    public int daysBetweenDates(String startDate, String endDate) throws ParseException {
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
        long startDateTime = dateFormat.parse(startDate).getTime();
        long endDateTime = dateFormat.parse(endDate).getTime();
        return (int) ((endDateTime - startDateTime) / (1000 * 3600 * 24));
    }
}
