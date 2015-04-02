package testJtextpane;

import javax.swing.*;

import java.awt.*;
import java.awt.event.*;

import javax.swing.Timer;

import java.io.File;
import java.io.Serializable;
import java.io.ObjectOutputStream;
import java.io.ObjectInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class TempusFugit extends JFrame implements ActionListener, Serializable, WindowListener
{
    private static final long serialVersionUID = 8012339137366360517L;
    String fileN = "tf.txt";
    public int ToL = 0;
    JLabel jl = new JLabel("" + ToL);
    private Timer timer;
    
    public void timerStart(){
        this.timer.start();
    }
    
    public void newTimer(){
        this.timer = new Timer(1000, this);
    }
    
    public void setToL(int Tol){
        this.ToL = Tol;
    }

    public TempusFugit()
    {
        timer = new Timer(1000, this);

        setBounds(250, 250, 250, 190);
        setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
        setLayout(new FlowLayout(FlowLayout.LEFT) );
        setVisible(true);
        add(jl);
        timer.start();
    }

    public void actionPerformed(ActionEvent e)
    {
        ++ToL;
        jl.setText("" + ToL);
        validate();
        repaint();
    }

    public static void main(String[] args)
    {
        File f = new File("tf.txt");
        TempusFugit tf = null;
        
        if(f.exists() && !f.isDirectory()) { 
            tf = TempusFugit.openObject();
        }else{
            tf = new TempusFugit();
        }
        
        if(tf == null){
            tf = new TempusFugit();
        }else{
            tf.setVisible(true);
            tf.newTimer();
            tf.timerStart();
        }
        
        tf.addWindowListener( tf );
    }

    public void windowDeactivated(WindowEvent e){}
    public void windowActivated(WindowEvent e){}
    public void windowDeiconified(WindowEvent e){}
    public void windowIconified(WindowEvent e){}
    public void windowClosed(WindowEvent e){}

    public void windowClosing(WindowEvent e)
    {
        try
        {
            FileOutputStream fos = new FileOutputStream(fileN);
            ObjectOutputStream out = new ObjectOutputStream(fos);
            out.writeObject(this);
            out.flush();
            out.close();
            setVisible(false);
            System.exit(0);
        }
        catch(IOException ex)
        {
            JOptionPane.showMessageDialog(null, ex);
            System.exit(1);
        }
    }

    public void windowOpened(WindowEvent e)
    {
        
    }
    
    public static TempusFugit openObject(){
        TempusFugit tf = null;// = new tempusFugit();
        try
        {
            System.out.println("hi");
            
            FileInputStream fis = new FileInputStream("tf.txt");
            ObjectInputStream in = new ObjectInputStream(fis);
            tf = (TempusFugit)in.readObject();
            //tf.ToL = tf.ToL;
            in.close();
            //tf.setVisible(false);
            
            
        }
        catch(IOException ex)
        {
            ex.printStackTrace();
        }
        catch(ClassNotFoundException ce)
        {
            ce.printStackTrace();
        }
        
        return tf;
    }
}