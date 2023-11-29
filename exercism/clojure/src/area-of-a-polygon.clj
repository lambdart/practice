(use ['clojure.string :only '(split)])

(defn read-input []
  (doall (line-seq (java.io.BufferedReader. *in*))))

(defn parse-str-to-int [string]
  (map #(Integer/parseInt %) (split string #" ")))

(defn get-ps [p]
  (concat (partition 2 1 p)
          (list (list (last p)
                      (first p)))))

(defn sum-ps [p]
  (let [x (first p)
        y (second p)]
    (- (* (first x) (second y))
       (* (second x) (first y)))))

(defn solution []
  (let [ans (->> (read-input)
                 (rest) ; discard the first read
                 (map parse-str-to-int) ;; parse line, split and convert to int
                 (get-ps) ;; get point partitions
                 (map sum-ps) ;; get partial sums
                 (reduce +)
                 (Math/abs))]
    (double (/ ans 2))))

(println (solution))
