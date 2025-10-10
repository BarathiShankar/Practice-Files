//My first java program to create event driven process
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class web
{
    public static void main(String[] args)
    {
        new app();
    }
}
class app extends JFrame implements ActionListener
{
    JLabel l1;
    JLabel l2;
    JTextField t1;
    JButton b1;
    app()
    {
        setLayout(new FlowLayout());
        l1=new JLabel("Enter Your Name : ");
        t1=new JTextField(20);
        b1=new JButton("Enter");
    add(l1);
    add(t1);
    add(b1);
    setVisible(true);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    b1.addActionListener(this);
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        String A=t1.getText();
        JOptionPane.showMessageDialog(null,"Mr/Mrs "+A+" How is my program","InfoBox",JOptionPane.INFORMATION_MESSAGE);
    }
}
