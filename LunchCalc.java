import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class LunchCalc extends JFrame implements ActionListener{

    int cost = 1000;
    JLabel label;

    JRadioButton radio1,radio2;
    JCheckBox check1,check2,check3;

    public void initialize(){
	this.setTitle("LunchCalc");

	JPanel panel1 = new JPanel();
	JPanel panel2 = new JPanel();

	radio1 = new JRadioButton("for here");
	radio2 = new JRadioButton("to go");
	
	ButtonGroup group = new ButtonGroup();
	group.add(radio1);
	group.add(radio2);

        check1 = new JCheckBox("with Drink");
        check2 = new JCheckBox("with Salad");
        check3 = new JCheckBox("with Cake");

	panel1.setLayout(new GridLayout(2,1));
	panel2.setLayout(new GridLayout(3,1));

        panel1.add(radio1);
	radio1.addActionListener(this);
	panel1.add(radio2);
	radio2.addActionListener(this);

	panel2.add(check1);
	check1.addActionListener(this);
	panel2.add(check2);
	check2.addActionListener(this);
	panel2.add(check3);
	check3.addActionListener(this);

	Container container = this.getContentPane();
	container.add(panel1,BorderLayout.WEST);
	container.add(panel2,BorderLayout.EAST);

	label = new JLabel(cost + "yen");
	label.setHorizontalAlignment(JLabel.CENTER);
	container.add(label,BorderLayout.SOUTH);

	this.pack();
	this.setVisible(true);
	this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String args[]){
	LunchCalc lc = new LunchCalc();
	lc.initialize();
    }

    
    public void actionPerformed(ActionEvent ae){

	cost = 1000;

	if(check1.isSelected()){
	    cost = cost + 200;
	}
	if(check2.isSelected()){
	    cost = cost + 300;
	}
	if(check3.isSelected()){
	    cost = cost + 500;
	}

	   
	if(radio1.isSelected()){
	    cost = (int)(cost * 1.1);
	   }else if(radio2.isSelected()){
	    cost = (int)(cost * 1.08);
	}

	label.setText(cost + "yen");
    }
}
		  
