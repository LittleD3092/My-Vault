SELECT DISTINCT student.id AS id, student.name AS name, course.title AS title
FROM student
JOIN takes ON student.id = takes.id
JOIN course ON takes.course_id = course.course_id
WHERE course.title LIKE 'Intro%';