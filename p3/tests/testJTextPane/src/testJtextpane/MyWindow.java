package testJtextpane;
import java.awt.Color;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import javax.swing.BorderFactory;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JTextPane;
import javax.swing.text.BadLocationException;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyledDocument;


public class MyWindow extends JFrame implements ActionListener{

    private static final long serialVersionUID = 1L;
    private JFrame frame;
    private JTextField textField;
    private JTextPane textPane;
    
    private StyledDocument doc;
    private SimpleAttributeSet attr;

    /**
     * Launch the application.
     */
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    File f = new File("file.txt");
                    MyWindow window = null;
                    
                    if(f.exists() && !f.isDirectory()) { 
                        window = MyWindow.openObject();
                    }else{
                        window = new MyWindow();
                    }
                    
                    if(window == null){
                        window = new MyWindow();
                    }
                    
                    window.frame.setVisible(true);
                    //window.addWindowListener(window);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    /**
     * Create the application.
     */
    public MyWindow() {
        initialize();
    }

    /**
     * Initialize the contents of the frame.
     */
    private void initialize() {
        frame = new JFrame();
        frame.setBounds(100, 100, 450, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        JPanel panel = new JPanel();
        frame.getContentPane().add(panel, BorderLayout.NORTH);
        
        textField = new JTextField();
        panel.add(textField);
        textField.setColumns(10);
        textField.addActionListener(this);
        
        JButton btnClick = new JButton("click");
        btnClick.addActionListener(this);
        panel.add(btnClick);
        
        JScrollPane scrollPane = new JScrollPane();
        frame.getContentPane().add(scrollPane, BorderLayout.CENTER);
        
        textPane = new JTextPane();
        doc = this.textPane.getStyledDocument();
        attr = new SimpleAttributeSet();
        scrollPane.setViewportView(textPane);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String text = this.textField.getText();
        if(text!=null && !"null".equals(text) && !"".equals(text.trim())){
            JLabel label = new JLabel(text);
            label.setOpaque(true);
            label.setBackground(Color.gray);
            label.setBorder(BorderFactory.createLineBorder(Color.black, 1));
            
            this.textPane.setCaretPosition(this.textPane.getDocument().getLength());
            this.textPane.insertComponent(label);
            
            label.addMouseListener(new MouseAdapter() {
                
                public void mouseClicked(MouseEvent event)
                {
                    //String text = ((JLabel)event.getSource()).getText();
                    //JOptionPane.showMessageDialog(MyWindow.this, text, "Information", JOptionPane.INFORMATION_MESSAGE);
                    try {
                        MyWindow newwindow = new MyWindow();
                        newwindow.frame.setVisible(true);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
                
            });
            
            try {
                doc.insertString(doc.getLength(), " ", attr);
            } catch (BadLocationException e2) {
                e2.printStackTrace();
            }
        }
        MyWindow.saveWindow(this);
        
    }
    
    public static MyWindow openObject(){
        MyWindow window = null;
        try
        {
            FileInputStream fis = new FileInputStream("file.txt");
            ObjectInputStream in = new ObjectInputStream(fis);
            window = (MyWindow) in.readObject();
            in.close();
        }
        catch(IOException ex)
        {
            ex.printStackTrace();
        }
        catch(ClassNotFoundException ce)
        {
            ce.printStackTrace();
        }
        
        return window;
    }
    
    public static void saveWindow(MyWindow window){
        try
        {
            System.out.println("sdsds");
            FileOutputStream fos = new FileOutputStream("file.txt");
            ObjectOutputStream out = new ObjectOutputStream(fos);
            out.writeObject(window);
            out.flush();
            out.close();
        }
        catch(IOException ex)
        {
            JOptionPane.showMessageDialog(null, ex);
            System.exit(1);
        }
    }

}
