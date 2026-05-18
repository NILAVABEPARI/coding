package com.example.SpringJDBCDemo.repo;

import com.example.SpringJDBCDemo.model.Student;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public class StudentRepo {
    private JdbcTemplate jdbc;

    public JdbcTemplate getJdbc() {
        return jdbc;
    }

    @Autowired
    public void setJdbc(JdbcTemplate jdbc) {
        System.out.println("inside set jdbc function");
        this.jdbc = jdbc;
    }

    public void save(Student s) {
//        System.out.println("Student Added");

        String sql = "insert into student (rollno, name, marks) values (?, ?, ?)";
        int rows = jdbc.update(sql, s.getRollNo(), s.getName(), s.getMarks());
        System.out.println(rows + " affected");
    }

    public List<Student> findAll() {

//        List<Student> students = new ArrayList<>();
//        return students;

        String sql = "select * from student";

//        RowMapper<Student> mapper = new RowMapper<Student>() {
//            @Override
//            public Student mapRow(ResultSet rs, int rowNum) throws SQLException {
//                Student s = new Student();
//                s.setRollNo(rs.getInt("rollno"));
//                s.setName(rs.getString("name"));
//                s.setMarks(rs.getInt("marks"));
//
//                return s;
//            }
//        };

//        // using lambda expression --
//        RowMapper<Student> mapper = (rs, rowNum) -> {
//            Student s = new Student();
//            s.setRollNo(rs.getInt("rollno"));
//            s.setName(rs.getString("name"));
//            s.setMarks(rs.getInt("marks"));
//            return s;
//        };
//
//        return jdbc.query(sql, mapper);

        // shorter form of lambda expression --

        return jdbc.query(sql, (rs, rowNum) -> {
            Student s = new Student();
            s.setRollNo(rs.getInt("rollno"));
            s.setName(rs.getString("name"));
            s.setMarks(rs.getInt("marks"));
            return s;
        });
    }
}
