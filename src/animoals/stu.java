package animoals;
import java.util.Arrays;
import java.util.Scanner;
public class stu {
    Scanner input = new Scanner(System.in);
    //属性
    private String name;
    private int age;
    private String gender;
    private int sorce;//学生平均分
    private int[] sub_sorce = new int[6];//顺序 语数英物化生
    private int total_points;
    public stu() {}//无参构造
    public stu(String stu_name,int stu_age,String stu_gender)//设置学生信息 带参构造
    {
        this.name = stu_name;
        this.age = stu_age;
        this.gender = stu_gender;
    }
    public void setAge(int age)
    {
        if(age<200)
        {
            this.age = age;
        }
        else {
            this.age = 18;
        }
    }
    public int getAge()
    {
        return this.age;
    }
    public void Subject_sorce()//学生成绩录入
    {
        for(int i=0;i<sub_sorce.length;i++)
        {
            switch(i)
            {
                case 0:
                    System.out.print("请输入语文成绩:");
                    break;
                case 1:
                    System.out.print("请输入数学成绩:");
                    break;
                case 2:
                    System.out.print("请输入英语成绩:");
                    break;
                case 3:
                    System.out.print("请输入物理成绩:");
                    break;
                case 4:
                    System.out.print("请输入化学成绩:");
                    break;
                case 5:
                    System.out.print("请输入生物成绩:");
                    break;
            }
            sub_sorce[i] = input.nextInt();
            total_points += sub_sorce[i];
        }
        sorce = total_points/6;
    }
    public void jugement(int line)
    {
        if(total_points-line>10&&total_points<510&&total_points-line<80)
        {
            System.out.println("读民办本科");
        }
        else if(total_points-line>80&&total_points<510)
        {
            System.out.println("读公办本科");
        }
        else if(total_points>510)
        {
            System.out.println("读一流本科");
        }
        else if(total_points<line)
        {
            System.out.println("滚去上大专");
        }
    }
    public void Print_mation()
    {
        System.out.println("姓名:"+name+" 年龄:"+age+" 性别:"+gender+" 平均分数:"+sorce+" 总分:"+total_points);
        System.out.println("语文"+" 数学"+" 英语"+" 物理"+" 化学"+" 生物");
        System.out.println(Arrays.toString(sub_sorce));
    }
}
