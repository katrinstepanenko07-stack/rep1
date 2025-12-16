-- 1.
WITH target_student AS (
    SELECT student_id
    FROM students
    WHERE student_id = 3
)
SELECT s.student_id, s.full_name
FROM students s
WHERE s.group_number = (SELECT group_number FROM students WHERE student_id = 3)
  AND s.student_id != 3
ORDER BY s.student_id
LIMIT 5;

-- 2. 
SELECT * 
FROM student_avg_grades 
WHERE student_id = 3;

-- 3. 
SELECT 
    sub.subjects_name,
    ROUND(AVG(g.grade)::NUMERIC, 2) as avg_grade,
    COUNT(g.grade) as total_grades
FROM grades g
JOIN subjects sub ON g.subjects_id = sub.subjects_id
WHERE sub.subjects_name = 'Информатика'
GROUP BY sub.subjects_name;

-- 4. 
SELECT n.note_id, s.full_name, n.note_text
FROM notes n
JOIN students s ON n.student_id = s.student_id
WHERE n.note_search_vector @@ to_tsquery('russian', 'информатик:*');

-- 5. 
BEGIN;

UPDATE attendance 
SET status = 'уважительная причина'
WHERE student_id = 4 
  AND date_attended = '2024-01-15';

INSERT INTO attendance (student_id, date_attended, status)
SELECT 4, '2024-01-15', 'уважительная причина'
WHERE NOT EXISTS (
    SELECT 1 FROM attendance 
    WHERE student_id = 4 
      AND date_attended = '2024-01-15'
);

COMMIT;