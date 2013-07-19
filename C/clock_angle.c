/*
    Find the angle between the hands of a clock.
*/

/*
Explanation:

Minutes Angle = (360 * m) / 60 = 6 * m where m is the minutes.
Hour Angle = ((360 * h) / 12) + (360 * m / 12 * 60) = 30 * h + m / 2
From the above two values get the difference by subtracting 
the bigger value from the smaller value.
If the difference is more than 180 then 360 - diff will be 
the acute angle else diff itself is the acute angle.

*/
