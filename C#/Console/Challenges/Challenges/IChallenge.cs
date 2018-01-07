namespace Challenges
{
    public interface IChallenge
    {
        string Description { get; }

        void Run();
    }
}
