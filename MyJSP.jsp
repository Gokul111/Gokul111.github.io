<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@ page import="com.l7.jdbc.book.dto.Book" %>
<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>learnJSP</title>
</head>
<body>
	<form action="">
		<%
		List<Book> books=new ArrayList<Book>();
		books = (List<Book>)request.getAttribute("booksList");
		System.out.println(books);
		%>

	</form>
	<input type="button" name="button1" value="testButton" />
</body>
</html>