package testJtextpane;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.JTextPane;
import javax.swing.SwingUtilities;
import javax.swing.text.BadLocationException;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyledDocument;

/**
 * Example in http://stackoverflow.com/questions/16371475/can-jlabel-be-added-to-jtextarea
 *
 */
@SuppressWarnings("serial")
public class JLabelToTextPane extends JFrame implements ActionListener
{
    JTextField tf;
    JTextPane tp ;
    JButton click;
    StyledDocument doc;
    SimpleAttributeSet attr;
    public void createAndShowGUI()
    {
        setTitle("Add JLabel to JTextPane");
        tf = new JTextField(10);
        tp = new JTextPane();
        click = new JButton("Click");
        doc = tp.getStyledDocument();
        attr = new SimpleAttributeSet();
        JScrollPane pane = new JScrollPane(tp);
        JPanel nPanel = new JPanel();
        nPanel.add(tf);nPanel.add(click);
        tf.addActionListener(this);
        click.addActionListener(this);
        Container c = getContentPane();
        c.add(nPanel,BorderLayout.NORTH);
        c.add(pane);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300,200);setLocationRelativeTo(null);setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent evt)
    {
        String text =  tf.getText();
        if (text!=null && !"null".equals(text) && !"".equals(text.trim()))
        {
            JLabel label = new JLabel(text);
            label.setOpaque(true);
            label.setBackground(Color.gray);
            label.setBorder(BorderFactory.createLineBorder(Color.black,1));
            tp.setCaretPosition(tp.getDocument().getLength());
            tp.insertComponent(label);
            label.addMouseListener(new MouseAdapter()
            {
                public void mouseClicked(MouseEvent evt)
                {
                    String text = ((JLabel)evt.getSource()).getText();
                    JOptionPane.showMessageDialog(JLabelToTextPane.this,"Hi, My text is "+text,"Information",JOptionPane.INFORMATION_MESSAGE);
                }
            });
            try
            {
                doc.insertString(doc.getLength(), " ", attr );  
            }
            catch (BadLocationException ex)
            {
                ex.printStackTrace();
            }
        }
    }
    public static void main(String[] args) 
    {
        SwingUtilities.invokeLater( new Runnable()
        {
            @Override
            public void run()
            {
                JLabelToTextPane lta = new JLabelToTextPane();
                lta.createAndShowGUI();
            }
        });
    }
}