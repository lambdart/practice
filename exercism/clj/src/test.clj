(ns test
  (:import java.util.UUID))

(defn positive-numbers
  ([] (positive-numbers 1))
  ([n] (lazy-seq (cons n (positive-numbers (inc n))))))

;; (take 1 (positive-numbers))

(defn gen-user []
  {:uuid (UUID/randomUUID)
   :color (rand-nth '(:red :green :blue))
   :height (+ 60 (rand-int 13))})

(apply = (take 10 (iterate (fn [_] (gen-user)) (gen-user))))

;; (defn users
;;   ([] (users (gen-user)))
;;   ([user] (lazy-seq (cons user (users (gen-user))))))

;; (apply = (take 10 (users)))
;; Spin up a fresh Clojure project, start REPL,
;; write functions in a source file, eval into REPL.

;; Exercises:
;; ■ heights: return N random ints in [60,72] uniformly.
;; ■ stream: produce an infinite lazy seq of even numbers and take the first
;; 20.
;; ■ tally: given a vector of maps, group‑by and reduce to a summary map.
;; You can use the Clojure Cheatsheet during the session (models real workflow).


(defn n-randoms [n]
  (take n (repeatedly (fn [] (+ 60 (rand-int 13))))))

(defn n-even [n]
  (take n (iterate (partial + 2) 0)))

(def vector-map [{:a 1 :b 2 :c 3}
                 {:a 4 :b 5 :c 6}])
;; {:a (1 4)
;;  :b (2 5)
;;  :c (3 6)}

(def vector-map [{:a 1 :b 2 :c 3}
                 {:a 4 :b 5 :c 6}])

(defn summary-map [m]
  (mapv
   (fn [k]
     (reduce (fn [acc cell]
               (assoc acc k (conj (get acc k) (get cell k))))
             {}
             m))
   (-> m first keys)))

(summary-map vector-map)

(group-by key (into [] cat data))



(assoc acc k (conj (get acc k)
                   (get m k)))

;; {:a (1 4)
;;  :b (2 5)
;;  :c (3 6)}

