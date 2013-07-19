/*
    Write a program to print string in the following pattern -
If i/p is 'abc' then o/p should be 'abbccccccbba'.
*/

/* Non -tested solution * /

public static void main(String[] args) {
String input = "abc";
int length = input.length();
StringBuilder str = new StringBuilder();
for (int i = 0; i < length; i++) {
for (int j = 0; j < i+1; j++) {
str.append(input.charAt(i));
}
}
System.out.println(str.toString()+str.reverse().toString());
}
