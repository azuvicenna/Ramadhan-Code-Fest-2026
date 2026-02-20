import { useDecision } from "../../hooks/useDecision";
import { questions } from "../../questions/decisionQuestions";
import QuestionCard from "../ui/QuizCard";
import { useNavigate, useParams } from "react-router-dom";

export default function QuizPage() {
	const { step } = useParams();
	const index = Number(step);
	const question = questions[index];
	const navigate = useNavigate();

	const { addAnswer } = useDecision();

	if (!question) {
		return <div className="">Question not found</div>;
	}
	const handleAnswer = (score: number) => {
		addAnswer(score);

		const nextIndex = index + 1;
		if (nextIndex < questions.length) {
			navigate(`/quiz/${nextIndex}`);
		} else {
			navigate("/result");
		}
	};

	return <QuestionCard data={question} onAnswer={handleAnswer} />;
}
