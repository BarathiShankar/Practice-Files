//First program to create a GUI integrated Java program
//Program to create an interactive panel based Quiz
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class web extends JFrame implements ActionListener
{
 JLabel l1,l2,l3,l4;
 JTextField t1,t2;
 JCheckBox c1,c2,c3;
 JRadioButton rb1,rb2,rb3;
 JButton b2;
 web()
 {
 setSize(350, 500);
 setLayout(new GridLayout(0, 1, 3, 5)); // 1 column, auto rows, 5px spacing
 l1=new JLabel("3. Which of the following belong to Asia : ");
 l2=new JLabel("1. On which year did India got it's Independence : ");
 l3=new JLabel("2. Which country did Hitler belong to : ");
 l4=new JLabel("Answers : 1. 1947 2. Germany 3. Saudi Arabia & Thailand");
 t1=new JTextField(20);
 t2=new JTextField(10);
 c1=new JCheckBox("Saudi Arabia");
 c3=new JCheckBox("Thailand");
 c2=new JCheckBox("Ukraine");
 rb1=new JRadioButton("Belgium");
 rb2=new JRadioButton("Germany");
 rb3=new JRadioButton("USA");
 b2=new JButton("Submit");
 add(l2);
 add(t1);
 add(l3);
 ButtonGroup rbg = new ButtonGroup();
 rbg.add(rb1);
 rbg.add(rb2);
 rbg.add(rb3);
 add(rb1);
 add(rb2);
 add(rb3);
 add(l1);
 add(c1); add(c2);
 add(c3);
 add(b2);
 add(t2);
 setVisible(true);
 setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 b2.addActionListener(this);
 }
 @Override
 public void actionPerformed(ActionEvent e) {
 int score = 0;
 String ans = t1.getText();
 if (ans.equals("1947")) {
 score += 10;
 }
 if (c1.isSelected() && !c2.isSelected()) {
 score += 5;
 }
 if (c3.isSelected() && !c2.isSelected()) {
 score += 5;
 }
 if (rb2.isSelected()) {
 score += 10;
 }
 t2.setText("Score : " + score);
 add(l4);
 setVisible(true);
 }
}
public class GUI_quiz
{
 public static void main(String[] args)
 {
 new web();
 }
}
