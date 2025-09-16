(ns coordinate-transformation)

(defn translate2d
  "Returns a function making use of a closure to
   perform a repeatable 2d translation of a coordinate pair."
  [dx dy]
  (fn [x y] [(+ x dx) (+ y dy)]))

(defn scale2d
  "Returns a function making use of a closure to
   perform a repeatable 2d scale of a coordinate pair."
  [sx sy]
  (fn [x y] [(* x sx) (* y sy)]))

(defn compose-transform
  "Create a composition function that returns a function that
   combines two functions to perform a repeatable transformation."
  [f g]
  (fn [x y] (apply g (f x y))))

(defn memoize-transform
  "Returns a function that memoizes the last result.
   If the arguments are the same as the last call,
   the memoized result is returned."
  [f]
  (let [r (atom nil)
        a (atom nil)
        b (atom nil)]
    (fn [x y]
      (if (and (= @a x) (= @b y))
        @r
        (do (reset! a x)
            (reset! b y)
            (reset! r (f x y)))))))

(let [fake-first (atom true)
      fake-transform (fn [_ _]
                       (if (clojure.core/deref fake-first)
                         (do (reset! fake-first false) [1 1])
                         false))
      memoized-transform (memoize-transform fake-transform)]
  [(= [1 1] (memoized-transform 5 5))
   (= [1 1] (memoized-transform 5 5))])

;; (def translator (translate2d -3 -5))
;; (def scaler (scale2d 2 2))

(def translator (translate2d -6 10))
(def compose-translate (compose-transform translator translator))

(= [-12 20] (compose-translate 0 0))

;; (translator 2 3)
;; (scaler 1 1)


