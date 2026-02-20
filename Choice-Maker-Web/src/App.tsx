import { Routes, Route } from "react-router-dom";
import HomePage from "./components/layout/HomePage";
import QuizPage from "./components/layout/QuizPage";
import ResultPage from "./components/layout/ResultPage";

function App() {
	return (
		<Routes>
			<Route path="/" element={<HomePage />} />
			<Route path="/quiz/:step" element={<QuizPage />} />
			<Route path="/result" element={<ResultPage />} />
		</Routes>
	);
}

export default App;
