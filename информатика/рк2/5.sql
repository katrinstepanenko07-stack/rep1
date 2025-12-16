BEGIN;

INSERT INTO students (full_name, group_number) 
VALUES ('Новиков Денис Александрович', 'ИУ1-12Б')
RETURNING student_id;

WITH new_student AS (
    SELECT student_id 
    FROM students 
    WHERE full_name = 'Новиков Денис Александрович'
)
INSERT INTO grades (student_id, subjects_id, grade)
SELECT new_student.student_id, sub.subjects_id, 4
FROM new_student, subjects sub;

COMMIT;