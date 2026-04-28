import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class DemoJdbc {
    public static void main(String[] args) throws Exception {

        String url = "jdbc:postgresql://localhost:5432/Demo";
        String userName = "postgres";
        String password = "HART";
        String sql = "select sname from student where sid = 1";
        String sql2 = "select * from student";

        // this statement is optional
        // Class.forName("org.postgresql.Driver");
        Connection con = DriverManager.getConnection(url,userName,password);
        System.out.println("Connection Established");

        Statement st = con.createStatement();
        ResultSet rs = st.executeQuery(sql);
        // System.out.println(rs.next()); // -- this will give boolean if result is found or not
        rs.next(); // we are doing this because the result of the query can give us multiple rows. by default the pointer of the row is before the starting of 1st row. so we need to do rs.next(); to make the pointer point to the 1st row of the result query
        String name = rs.getString("sname");
        System.out.println("name of the student is " + name);

        System.out.println("----------");

        ResultSet rs2 = st.executeQuery(sql2);
        while(rs2.next()) {
            System.out.print(rs2.getString(1) + " - ");
            System.out.print(rs2.getInt(2) + " - ");
            System.out.println(rs2.getInt(3));
        }
        con.close();
        System.out.println("Connection close");
    }
}
