(ns solution.sublist)

;; Determine the relation between list1 and list2 and return
;; the relation as a Clojure keyword. The function classify should either
;; return :sublist, :superlist, :equal or:unequal.
(defn classify [list1 list2]
  (let [[A B result] (if (> (count list1)
                            (count list2))
                       [list2 list1 :superlist]
                       [list1 list2 :sublist])]
    (cond
      (= A B) :equal
      (or (empty? A) (empty? B)) result
      (= (filter #(contains? B %) A) A) result
      :else :unequal)))
