(SELECT student.id AS id, student.name AS name
FROM student
JOIN takes ON student.id = takes.id
JOIN course ON takes.course_id = course.course_id
WHERE course.dept_name = 'Comp. Sci.')
UNION
(SELECT student.id AS id, student.name AS name
FROM student
JOIN takes ON student.id = takes.id
JOIN course ON takes.course_id = course.course_id
WHERE course.dept_name = 'Elec. Eng.')
ORDER BY name id;