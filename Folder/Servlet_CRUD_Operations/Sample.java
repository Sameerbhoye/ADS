package com.sres;

import jakarta.servlet.ServletException;

import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

/**
 * Servlet implementation class Sample1
 */
public class Sample1 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Sample1() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		// 1.insert 2. update 3. delete 4. display choice
		int x=Integer.parseInt(request.getParameter("ch"));
		try {
		Class.forName("com.mysql.cj.jdbc.Driver");
		System.out.println("Driver Class is loaded");
		Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/college","root","samir");
		if(con!=null) {
			
			System.out.println("The connection is established");
			
		if(x==1) {
			  //insert
			int rn=Integer.parseInt(request.getParameter("rollno"));
			String en=request.getParameter("name");
			int mk=Integer.parseInt(request.getParameter("marks"));
			PreparedStatement ps=con.prepareStatement("insert into student (rollno,name,marks) values (?,?,?)");
			ps.setInt(1,rn);
			ps.setString(2,en);
			ps.setInt(3,mk);
			int rowaffected=ps.executeUpdate();
			System.out.println("No of Rows affected are : "+rowaffected);
		}
		if(x==2) {
			//update
			int rno=Integer.parseInt(request.getParameter("rollno"));
			int mks=Integer.parseInt(request.getParameter("marks"));
			PreparedStatement ps=con.prepareStatement("update student set marks=?  where rollno=?" );
			ps.setInt(1, mks);
			ps.setInt(2, rno);
			int rowaffected=ps.executeUpdate();
			System.out.println("The number of rows affected are : "+rowaffected);
		}
		if(x==3) {
			//delete
			int rno=Integer.parseInt(request.getParameter("rollno"));
			PreparedStatement ps=con.prepareStatement("delete from student where rollno=?");
			ps.setInt(1, rno);
			int rowaffected=ps.executeUpdate();
			System.out.println("The number of rows affected are :"+rowaffected);
		}
		if(x==4) {
			//display
			PreparedStatement ps=con.prepareStatement("select * from student");
			ResultSet rs=ps.executeQuery();
			System.out.println("Student Details are:-");
			while(rs.next()) {
				System.out.println("Roll Nos:-"+rs.getInt(1));
				System.out.println("Student Name:-"+rs.getString(2));
				System.out.println("Marks:-"+rs.getInt(3));
			}
		}
		
		}
		else {
			System.out.println("Database Connection is failed");
		}
		
		}
		catch (Exception e) {
			System.out.println(e);
		}
	}

}

