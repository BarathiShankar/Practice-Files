//Program to create a email login and verify ther data provided by exception handling and GUI
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class Email_creator extends JFrame implements ActionListener {
    JTextField username, phone, recoveryEmail, birthday;
    JPasswordField password, confirmPassword;
    JButton create, reset, cancel;
    JLabel result;
    w10q3()
    {
        setTitle("Create your Google Account");
        setSize(400, 400);
        setLayout(new GridLayout(0, 1, 5, 5));
        username = new JTextField();
        password = new JPasswordField();
        confirmPassword = new JPasswordField();
        phone = new JTextField();
        recoveryEmail = new JTextField();
        birthday = new JTextField();
        create = new JButton("Create Account");
        reset = new JButton("Reset");
        cancel = new JButton("Cancel");
        result = new JLabel("");
        add(new JLabel("Username:"));
        add(username);
        add(new JLabel("Password:"));
        add(password);
        add(new JLabel("Confirm Password:"));
        add(confirmPassword);
        add(new JLabel("Phone Number:"));
        add(phone);
        add(new JLabel("Recovery Email:"));
        add(recoveryEmail);
        add(new JLabel("Birthday (DD/MM/YYYY):"));
        add(birthday);
        add(create);
        add(reset);
        add(cancel);
        add(result);
        create.addActionListener(this);
        reset.addActionListener(e -> clearFields());
        cancel.addActionListener(e -> System.exit(0));

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            String user = username.getText().trim();
            String pass = new String(password.getPassword());
            String confirm = new String(confirmPassword.getPassword());
            String phoneNum = phone.getText().trim();
            String email = recoveryEmail.getText().trim();
            String dob = birthday.getText().trim();

            // Rule i: Password match and strength
            if (!pass.equals(confirm)) throw new Exception("Passwords do not match.");
            if (pass.length() < 8) throw new Exception("Password must be at least 8 characters.");

            // Rule ii: Empty fields
            if (user.isEmpty() || phoneNum.isEmpty() || email.isEmpty() || dob.isEmpty())
                throw new Exception("All fields must be filled.");

            // Rule iii: Email format
            if (!email.matches("^[\\w.-]+@[\\w.-]+\\.\\w{2,}$"))
                throw new Exception("Invalid recovery email address.");

            result.setText("Account created successfully!");
        } catch (Exception ex) {
            result.setText("Error: " + ex.getMessage());
        }
    }
    void clearFields() {
        username.setText("");
        password.setText("");
        confirmPassword.setText("");
        phone.setText("");
        recoveryEmail.setText("");
        birthday.setText("");
        result.setText("");
    }
    public static void main(String[] args) {
        new Email_creator();
    }
}
//COMPLETED
