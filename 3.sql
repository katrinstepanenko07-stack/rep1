CREATE INDEX idx_students_group_number ON students(group_number);
CREATE INDEX idx_grades_student_id ON grades(student_id);

-- GIN 
ALTER TABLE notes ADD COLUMN note_search_vector tsvector;
UPDATE notes SET note_search_vector = to_tsvector('russian', note_text);
CREATE INDEX idx_notes_note_search_vector ON notes USING gin(note_search_vector);