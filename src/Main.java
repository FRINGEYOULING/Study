// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.Arrays;
import java.util.Scanner;
import animoals.Dog;
import animoals.stu;
import animoals.People;

public class Main {
    static char gender;

    public static void main(String[] args) {
        // Press Alt+Enter with your caret at the highlighted text to see how
        // IntelliJ IDEA suggests fixing it.
//        Dog myDog = new Dog();
//        myDog.brand = "拉不拉多";
//        myDog.age = 6;
//        myDog.color = "White";
//        myDog.name = "旺财";
//        myDog.eat();
//        myDog.sleep();
        stu student = new stu("张三",18,"男");
        student.Subject_sorce();
        student.Print_mation();
        student.jugement(397);
//        int sum = 0;
//        int[] nums = new int[5];
//        nums = Arrays.copyOf(nums,nums.length*2);
//        System.out.println(nums.length);
//        Scanner input = new Scanner(System.in);
//        System.out.print("请输入用户名:");
//        String name = input.next();
//        System.out.print("请输入年龄:");
//        byte Age = input.nextByte();
//        do {
//            System.out.print("请输入性别(男或女):");
//            gender = input.next().charAt(0);
//            if (gender!='男'&&gender!='女') {
//                System.out.println("性别不存在,请重新输入");
//            }
//        }while(gender!='男'&&gender!='女');
//        System.out.println("用户名:"+name);
//        System.out.printf("年龄:%d\n",Age);
//        System.out.println("性别:"+gender);
//        for(int i=1;i<6;i++)
//        {
//            System.out.println("输入第"+i+"同学的分数");
//            int sorce = input.nextInt();
//            sum += sorce;
//        }
//        System.out.println("平均分"+(sum/5));
        function(30);
    }
    public static void function(int num){
        for(int i=0;i<num;i++)
        {
            System.out.print('-');
        }
    }
}