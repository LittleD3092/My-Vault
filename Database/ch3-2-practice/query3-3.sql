SELECT distinct student.id AS id, student.name AS name
FROM student
JOIN takes ON student.id = takes.id
WHERE takes.course_id = 'CS-101';
