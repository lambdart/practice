(ns two-fer)

(defn two-fer
  "Return the two-fer string."
  [& [arg]]
  (format "One for %s, one for me." (or arg "you")))
