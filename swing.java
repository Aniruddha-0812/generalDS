package swing;

import javax.swing.*;
import java.awt.*;
public class swing{
   public JFrame f;
   public JPanel p1;
   public JPanel p2;
   public JLabel lab;
   public JLabel lab1;
   public JLabel lab2;
   public JTable tab;
   public swing(){
      f=new JFrame("Bank Account Details");
	  f.setVisible(true);
	  f.setSize(600,400);
	  f.setLayout(new BorderLayout());
	  f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	  p1=new JPanel();
	  p2=new JPanel();
	  p1.setBackground(Color.YELLOW);
	  p1.setBackground(Color.WHITE);
	  lab=new JLabel("BANK ACCOUNT DETAILS");
	  String[] col={"",""};
	  String[][] data={{"Account Name:","Roger Kint"},
	                   {"Account Number:","8001122334"},
					   {"Branch Name:","Pune"},
					   {"Date of Account Opening:","10-04-2020"},
					   {"Account Type:","Savings"},
					   {"Account Balance:","Rs.60000/-"},
					   {"Holder's Contact:","08001166448"},
					   {"Holder's Email Address:","abc1@gmail.com"},
					   {"Holder's Address:","Pune"}
	                  };
       tab=new JTable(data,col);
	   JScrollPane pane=new JScrollPane(tab);
	   pane.setPreferredSize(new Dimension(600,200));
	   p1.add(lab);
	   p2.add(pane);
	   f.add(p1,BorderLayout.NORTH);
	   f.add(p2,BorderLayout.CENTER);
    }
   public static void main(String args[])
   {
   new swing();
   }
}
